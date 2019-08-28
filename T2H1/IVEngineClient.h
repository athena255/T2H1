#pragma once
#include "stdafx.h"
#include "Offsets.h"
#include "hook.h"
#include "Vector.h"
#include "Vector2D.h"
#include "QAngle.h"
#include "VMatrix.h"
#include "Color.h"

#define SIGNONSTATE_NONE		0	// no state yet, about to connect
#define SIGNONSTATE_CHALLENGE	1	// client challenging server, all OOB packets
#define SIGNONSTATE_CONNECTED	2	// client is connected to server, netchans ready
#define SIGNONSTATE_NEW			3	// just got serverinfo and string tables
#define SIGNONSTATE_PRESPAWN	4	// received signon buffers
#define SIGNONSTATE_SPAWN		5	// ready to receive entity packets
#define SIGNONSTATE_FULL		6	// we are fully connected, first non-delta packet received
#define SIGNONSTATE_CHANGELEVEL	7	// server is changing level, please wait

typedef struct InputContextHandle_t__ *InputContextHandle_t;
struct client_textmessage_t;
struct model_t;
class SurfInfo;
class IMaterial;
class CSentence;
class CAudioSource;
class AudioState_t;
class ISpatialQuery;
class IMaterialSystem;
class CPhysCollide;
class IAchievementMgr;
#define FLOW_OUTGOING	0		
#define FLOW_INCOMING	1
#define MAX_FLOWS		2		// in & out

class INetChannelInfo
{
public:

	enum {
		GENERIC = 0,	// must be first and is default group
		LOCALPLAYER,	// bytes for local player entity update
		OTHERPLAYERS,	// bytes for other players update
		ENTITIES,		// all other entity bytes
		SOUNDS,			// game sounds
		EVENTS,			// event messages
		USERMESSAGES,	// user messages
		ENTMESSAGES,	// entity messages
		VOICE,			// voice data
		STRINGTABLE,	// a stringtable update
		MOVE,			// client move cmds
		STRINGCMD,		// string command
		SIGNON,			// various signondata
		TOTAL,			// must be last and is not a real group
	};

	virtual const char  *GetName(void) const = 0;	// get channel name
	virtual const char  *GetAddress(void) const = 0; // get channel IP address as string
	virtual float		GetTime(void) const = 0;	// current net time
	virtual float		GetTimeConnected(void) const = 0;	// get connection time in seconds
	virtual int			GetBufferSize(void) const = 0;	// netchannel packet history size
	virtual int			GetDataRate(void) const = 0; // send data rate in byte/sec

	virtual bool		IsLoopback(void) const = 0;	// true if loopback channel
	virtual bool		IsTimingOut(void) const = 0;	// true if timing out
	virtual bool		IsPlayback(void) const = 0;	// true if demo playback

	virtual float		GetLatency(int flow) const = 0;	 // current latency (RTT), more accurate but jittering
	virtual float		GetAvgLatency(int flow) const = 0; // average packet latency in seconds
	virtual float		GetAvgLoss(int flow) const = 0;	 // avg packet loss[0..1]
	virtual float		GetAvgChoke(int flow) const = 0;	 // avg packet choke[0..1]
	virtual float		GetAvgData(int flow) const = 0;	 // data flow in bytes/sec
	virtual float		GetAvgPackets(int flow) const = 0; // avg packets/sec
	virtual int			GetTotalData(int flow) const = 0;	 // total flow in/out in bytes
	virtual int			GetSequenceNr(int flow) const = 0;	// last send seq number
	virtual bool		IsValidPacket(int flow, int frame_number) const = 0; // true if packet was not lost/dropped/chocked/flushed
	virtual float		GetPacketTime(int flow, int frame_number) const = 0; // time when packet was send
	virtual int			GetPacketBytes(int flow, int frame_number, int group) const = 0; // group size of this packet
	virtual bool		GetStreamProgress(int flow, int *received, int *total) const = 0;  // TCP progress if transmitting
	virtual float		GetTimeSinceLastReceived(void) const = 0;	// get time since last recieved packet in seconds
	virtual	float		GetCommandInterpolationAmount(int flow, int frame_number) const = 0;
	virtual void		GetPacketResponseLatency(int flow, int frame_number, int *pnLatencyMsecs, int *pnChoke) const = 0;
	virtual void		GetRemoteFramerate(float *pflFrameTime, float *pflFrameTimeStdDeviation) const = 0;

	virtual float		GetTimeoutSeconds() const = 0;
};

class ISPSharedMemory;
class CGamestatsData;
class KeyValues;
class CSteamAPIContext;
struct Frustum_t;

typedef void(*pfnDemoCustomDataCallback)(uint8_t *pData, size_t iSize);


typedef struct player_info_s
{
	char            szName[128];        //0x0010 - Player Name
	int             userId;             //0x0090 - Unique Server Identifier
} player_info_t;

class IMapOverview // : public IBaseInterface
{
public:
	virtual	~IMapOverview(void) {};

	virtual	void SetVisible(bool state) = 0;	// set map panel visible
	virtual void SetBounds(int x, int y, int wide, int tall) = 0; // set pos & size
	virtual void SetZoom(float zoom) = 0; // set zoom
	virtual void SetTime(float time) = 0; // set game time
	virtual void SetAngle(float angle) = 0; // set map orientation
	virtual void SetFollowAngle(bool state) = 0; // if true, map rotates with spectators view
	virtual void SetCenter(Vector2D &mappos) = 0; // set map pos in center of panel
	virtual void SetPlayerPositions(int index, const Vector &position, const QAngle &angle) = 0; // update player position
	virtual Vector2D WorldToMap(Vector &worldpos) = 0; // convert 3d world to 2d map pos

	virtual bool  IsVisible(void) = 0;	// true if MapOverview is visible
	virtual void  GetBounds(int& x, int& y, int& wide, int& tall) = 0; // get current pos & size
	virtual float GetZoom(void) = 0;

	// deatils properties
	virtual	void ShowPlayerNames(bool state) = 0;	// show player names under icons
	virtual	void ShowTracers(bool state) = 0;	// show shooting traces as lines
	virtual	void ShowExplosions(bool state) = 0;	// show, smoke, flash & HE grenades
	virtual	void ShowHealth(bool state) = 0;		// show player health under icon
	virtual	void ShowHurts(bool state) = 0;	// show player icon flashing if player is hurt
	virtual	void ShowTracks(float seconds) = 0; // show player trails for n seconds
};

//-----------------------------------------------------------------------------
// Purpose: Interface exposed from the engine to the client .dll
//-----------------------------------------------------------------------------
class IVEngineClient013
{
public:
	// Find the model's surfaces that intersect the given sphere.
	// Returns the number of surfaces filled in.
	virtual int					GetIntersectingSurfaces(
		const model_t *model,
		const Vector &vCenter,
		const float radius,
		const bool bOnlyVisibleSurfaces,	// Only return surfaces visible to vCenter.
		SurfInfo *pInfos,
		const int nMaxInfos) = 0;

	// Get the lighting intensivty for a specified point
	// If bClamp is specified, the resulting Vector is restricted to the 0.0 to 1.0 for each element
	virtual Vector				GetLightForPoint(const Vector &pos, bool bClamp) = 0;

	// Traces the line and reports the material impacted as well as the lighting information for the impact point
	virtual IMaterial			*TraceLineMaterialAndLighting(const Vector &start, const Vector &end,
		Vector &diffuseLightColor, Vector& baseColor) = 0;

	// Given an input text buffer data pointer, parses a single token into the variable token and returns the new
	//  reading position
	virtual const char			*ParseFile(const char *data, char *token, int maxlen) = 0;
	virtual bool				CopyLocalFile(const char *source, const char *destination) = 0;

	// Gets the dimensions of the game window
	virtual void				GetScreenSize(int& width, int& height) = 0;

	// Forwards szCmdString to the server, sent reliably if bReliable is set
	virtual void				ServerCmd(const char *szCmdString, bool bReliable = true) = 0;  // 26
	// Inserts szCmdString into the command buffer as if it was typed by the client to his/her console.
	// Note: Calls to this are checked against FCVAR_CLIENTCMD_CAN_EXECUTE (if that bit is not set, then this function can't change it).
	//       Call ClientCmd_Unrestricted to have access to FCVAR_CLIENTCMD_CAN_EXECUTE vars.
	virtual void				ClientCmd(const char *szCmdString) = 0;

	// Fill in the player info structure for the specified player index (name, model, etc.)
	virtual bool				GetPlayerInfo(int ent_num, player_info_t *pinfo) = 0;

	// Retrieve the player entity number for a specified userID
	virtual int					GetPlayerForUserID(int userID) = 0;

	// Retrieves text message system information for the specified message by name
	virtual client_textmessage_t *TextMessageGet(const char *pName) = 0;

	// Returns true if the console is visible
	virtual bool				Con_IsVisible(void) = 0;

	// Get the entity index of the local player
	virtual int					GetLocalPlayer(void) = 0; // 41

	// Client DLL is hooking a model, loads the model into memory and returns  pointer to the model_t
	virtual const model_t		*LoadModel(const char *pName, bool bProp = false) = 0;

	// Get accurate, sub-frame clock ( profiling use )
	virtual float				Time(void) = 0;

	// Get the exact server timesstamp ( server time ) from the last message received from the server
	virtual float				GetLastTimeStamp(void) = 0;

	// Given a CAudioSource (opaque pointer), retrieve the underlying CSentence object ( stores the words, phonemes, and close
	//  captioning data )
	virtual CSentence			*GetSentence(CAudioSource *pAudioSource) = 0;
	// Given a CAudioSource, determines the length of the underlying audio file (.wav, .mp3, etc.)
	virtual float				GetSentenceLength(CAudioSource *pAudioSource) = 0;
	// Returns true if the sound is streaming off of the hard disk (instead of being memory resident)
	virtual bool				IsStreaming(CAudioSource *pAudioSource) const = 0;

	// Copy current view orientation into va
	virtual void				GetViewAngles(QAngle& va) = 0;
	// Set current view orientation from va
	virtual void				SetViewAngles(QAngle& va) = 0;

	// Retrieve the current game's maxclients setting
	virtual int					GetMaxClients(void) = 0;

	// Given the string pBinding which may be bound to a key, 
	//  returns the string name of the key to which this string is bound. Returns NULL if no such binding exists
	virtual	const char			*Key_LookupBinding(const char *pBinding) = 0;

	// Given the name of the key "mouse1", "e", "tab", etc., return the string it is bound to "+jump", "impulse 50", etc.
	virtual const char			*Key_BindingForKey(uintptr_t code) = 0;

	// key trapping (for binding keys)
	virtual void				StartKeyTrapMode(void) = 0;
	virtual bool				CheckDoneKeyTrapping(uintptr_t &code) = 0;

	// Returns true if the player is fully connected and active in game (i.e, not still loading)
	virtual bool				IsInGame(void) = 0;
	// Returns true if the player is connected, but not necessarily active in game (could still be loading)
	virtual bool				IsConnected(void) = 0;
	// Returns true if the loading plaque should be drawn
	virtual bool				IsDrawingLoadingImage(void) = 0;

	// Prints the formatted string to the notification area of the screen ( down the right hand edge
	//  numbered lines starting at position 0
	virtual void				Con_NPrintf(int pos, uintptr_t *fmt) = 0;
	// Similar to Con_NPrintf, but allows specifying custom text color and duration information
	virtual void				Con_NXPrintf(const struct con_nprint_s *info, uintptr_t *fmt, ...) = 0;

	// Is the specified world-space bounding box inside the view frustum?
	virtual int					IsBoxVisible(const Vector& mins, const Vector& maxs) = 0;

	// Is the specified world-space boudning box in the same PVS cluster as the view origin?
	virtual int					IsBoxInViewCluster(const Vector& mins, const Vector& maxs) = 0;

	// Returns true if the specified box is outside of the view frustum and should be culled
	virtual bool				CullBox(const Vector& mins, const Vector& maxs) = 0;

	// Allow the sound system to paint additional data (during lengthy rendering operations) to prevent stuttering sound.
	virtual void				Sound_ExtraUpdate(void) = 0;

	// Get the current game directory ( e.g., hl2, tf2, cstrike, hl1 )
	virtual const char			*GetGameDirectory(void) = 0;

	// Get access to the world to screen transformation matrix
	virtual const VMatrix& 		WorldToScreenMatrix() = 0;

	// Get the matrix to move a point from world space into view space
	// (translate and rotate so the camera is at the origin looking down X).
	virtual const VMatrix& 		WorldToViewMatrix() = 0;

	// The .bsp file can have mod-specified data lumps. These APIs are for working with such game lumps.

	// Get mod-specified lump version id for the specified game data lump
	virtual int					GameLumpVersion(int lumpId) const = 0;
	// Get the raw size of the specified game data lump.
	virtual int					GameLumpSize(int lumpId) const = 0;
	// Loads a game lump off disk, writing the data into the buffer pointed to bye pBuffer
	// Returns false if the data can't be read or the destination buffer is too small
	virtual bool				LoadGameLump(int lumpId, void* pBuffer, int size) = 0;

	// Returns the number of leaves in the level
	virtual int					LevelLeafCount() const = 0;

	// Gets a way to perform spatial queries on the BSP tree
	virtual ISpatialQuery*		GetBSPTreeQuery() = 0;

	// Convert texlight to gamma...
	virtual void		LinearToGamma(float* linear, float* gamma) = 0;

	// Get the lightstyle value
	virtual float		LightStyleValue(int style) = 0;

	// Computes light due to dynamic lighting at a point
	// If the normal isn't specified, then it'll return the maximum lighting
	virtual void		ComputeDynamicLighting(const Vector& pt, const Vector* pNormal, Vector& color) = 0;

	// Returns the color of the ambient light
	virtual void		GetAmbientLightColor(Vector& color) = 0;

	// Returns the dx support level
	virtual int			GetDXSupportLevel() = 0;

	// GR - returns the HDR support status
	virtual bool        SupportsHDR() = 0;

	// Replace the engine's material system pointer.
	virtual void		Mat_Stub(IMaterialSystem *pMatSys) = 0;

	// Get the name of the current map
	virtual void GetChapterName(char *pchBuff, int iMaxLength) = 0;
	virtual char const	*GetLevelName(void) = 0;
	virtual int	GetLevelVersion(void) = 0;
#if !defined( NO_VOICE )
	// Obtain access to the voice tweaking API
	virtual struct IVoiceTweak_s *GetVoiceTweakAPI(void) = 0;
#endif
	// Tell engine stats gathering system that the rendering frame is beginning/ending
	virtual void		EngineStats_BeginFrame(void) = 0;
	virtual void		EngineStats_EndFrame(void) = 0;

	// This tells the engine to fire any events (temp entity messages) that it has queued up this frame. 
	// It should only be called once per frame.
	virtual void		FireEvents() = 0;

	// Returns an area index if all the leaves are in the same area. If they span multple areas, then it returns -1.
	virtual int			GetLeavesArea(int *pLeaves, int nLeaves) = 0;

	// Returns true if the box touches the specified area's frustum.
	virtual bool		DoesBoxTouchAreaFrustum(const Vector &mins, const Vector &maxs, int iArea) = 0;

	// Sets the hearing origin (i.e., the origin and orientation of the listener so that the sound system can spatialize 
	//  sound appropriately ).
	virtual void		SetAudioState(const AudioState_t& state) = 0;

	// Sentences / sentence groups
	virtual int			SentenceGroupPick(int groupIndex, char *name, int nameBufLen) = 0;
	virtual int			SentenceGroupPickSequential(int groupIndex, char *name, int nameBufLen, int sentenceIndex, int reset) = 0;
	virtual int			SentenceIndexFromName(const char *pSentenceName) = 0;
	virtual const char *SentenceNameFromIndex(int sentenceIndex) = 0;
	virtual int			SentenceGroupIndexFromName(const char *pGroupName) = 0;
	virtual const char *SentenceGroupNameFromIndex(int groupIndex) = 0;
	virtual float		SentenceLength(int sentenceIndex) = 0;

	// Computes light due to dynamic lighting at a point
	// If the normal isn't specified, then it'll return the maximum lighting
	// If pBoxColors is specified (it's an array of 6), then it'll copy the light contribution at each box side.
	virtual void		ComputeLighting(const Vector& pt, const Vector* pNormal, bool bClamp, Vector& color, Vector *pBoxColors = NULL) = 0;

	// Activates/deactivates an occluder...
	virtual void		ActivateOccluder(int nOccluderIndex, bool bActive) = 0;
	virtual bool		IsOccluded(const Vector &vecAbsMins, const Vector &vecAbsMaxs) = 0;

	// The save restore system allocates memory from a shared memory pool, use this allocator to allocate/free saverestore 
	//  memory.
	virtual void		*SaveAllocMemory(size_t num, size_t size) = 0;
	virtual void		SaveFreeMemory(void *pSaveMem) = 0;

	// returns info interface for client netchannel
	virtual INetChannelInfo	*GetNetChannelInfo(void) = 0;

	// Debugging functionality:
	// Very slow routine to draw a physics model
	virtual void		DebugDrawPhysCollide(const CPhysCollide *pCollide, IMaterial *pMaterial, matrix3x4_t& transform, const uintptr_t &color) = 0;
	// This can be used to notify test scripts that we're at a particular spot in the code.
	virtual void		CheckPoint(const char *pName) = 0;
	// Draw portals if r_DrawPortals is set (Debugging only)
	virtual void		DrawPortals() = 0;
	// Determine whether the client is playing back or recording a demo
	virtual bool		IsPlayingDemo(void) = 0;
	virtual bool		IsRecordingDemo(void) = 0;
	virtual bool		IsPlayingTimeDemo(void) = 0;
	virtual int			GetDemoRecordingTick(void) = 0;
	virtual int			GetDemoPlaybackTick(void) = 0;
	virtual int			GetDemoPlaybackStartTick(void) = 0;
	virtual float		GetDemoPlaybackTimeScale(void) = 0;
	virtual int			GetDemoPlaybackTotalTicks(void) = 0;
	// Is the game paused?
	virtual bool		IsPaused(void) = 0;
	// Is the game currently taking a screenshot?
	virtual bool		IsTakingScreenshot(void) = 0;
	// Is this a HLTV broadcast ?
	virtual bool		IsHLTV(void) = 0;
	// is this level loaded as just the background to the main menu? (active, but unplayable)
	virtual bool		IsLevelMainMenuBackground(void) = 0;
	// returns the name of the background level
	virtual void		GetMainMenuBackgroundName(char *dest, int destlen) = 0;

	// Get video modes
	virtual void		GetVideoModes(int &nCount, uintptr_t *&pModes) = 0;

	// Occlusion system control
	virtual void		SetOcclusionParameters(const uintptr_t &params) = 0;

	// What language is the user expecting to hear .wavs in, "english" or another...
	virtual void		GetUILanguage(char *dest, int destlen) = 0;

	// Can skybox be seen from a particular point?
	virtual uintptr_t IsSkyboxVisibleFromPoint(const Vector &vecPoint) = 0;

	// Get the pristine map entity lump string.  (e.g., used by CS to reload the map entities when restarting a round.)
	virtual const char*	GetMapEntitiesString() = 0;

	// Is the engine in map edit mode ?
	virtual bool		IsInEditMode(void) = 0;

	// current screen aspect ratio (eg. 4.0f/3.0f, 16.0f/9.0f)
	virtual float		GetScreenAspectRatio() = 0;

	// allow the game UI to login a user
	virtual bool		REMOVED_SteamRefreshLogin(const char *password, bool isSecure) = 0;
	virtual bool		REMOVED_SteamProcessCall(bool & finished) = 0;

	// allow other modules to know about engine versioning (one use is a proxy for network compatability)
	virtual unsigned int	GetEngineBuildNumber() = 0; // engines build
	virtual const char *	GetProductVersionString() = 0; // mods version number (steam.inf)

	// Communicates to the color correction editor that it's time to grab the pre-color corrected frame
	// Passes in the actual size of the viewport
	virtual void			GrabPreColorCorrectedFrame(int x, int y, int width, int height) = 0;

	virtual bool			IsHammerRunning() const = 0;

	// Inserts szCmdString into the command buffer as if it was typed by the client to his/her console.
	// And then executes the command string immediately (vs ClientCmd() which executes in the next frame)
	//
	// Note: this is NOT checked against the FCVAR_CLIENTCMD_CAN_EXECUTE vars.
	virtual void			ExecuteClientCmd(const char *szCmdString) = 0;

	// returns if the loaded map was processed with HDR info. This will be set regardless
	// of what HDR mode the player is in.
	virtual bool MapHasHDRLighting(void) = 0;

	virtual int	GetAppID() = 0;

	// Just get the leaf ambient light - no caching, no samples
	virtual Vector			GetLightForPointFast(const Vector &pos, bool bClamp) = 0;

	// This version does NOT check against FCVAR_CLIENTCMD_CAN_EXECUTE.
	virtual void			ClientCmd_Unrestricted(const char *szCmdString) = 0;

	// This used to be accessible through the cl_restrict_server_commands cvar.
	// By default, Valve games restrict the server to only being able to execute commands marked with FCVAR_SERVER_CAN_EXECUTE.
	// By default, mods are allowed to execute any server commands, and they can restrict the server's ability to execute client
	// commands with this function.
	virtual void			SetRestrictServerCommands(bool bRestrict) = 0;

	// If set to true (defaults to true for Valve games and false for others), then IVEngineClient::ClientCmd
	// can only execute things marked with FCVAR_CLIENTCMD_CAN_EXECUTE.
	virtual void			SetRestrictClientCommands(bool bRestrict) = 0;

	// Sets the client renderable for an overlay's material proxy to bind to
	virtual void			SetOverlayBindProxy(int iOverlayID, void *pBindProxy) = 0;

	virtual bool			CopyFrameBufferToMaterial(const char *pMaterialName) = 0;

	// Matchmaking
	virtual void			ChangeTeam(const char *pTeamName) = 0;

	// Causes the engine to read in the user's configuration on disk
	virtual void			ReadConfiguration(const bool readDefault = false) = 0;

	virtual void SetAchievementMgr(IAchievementMgr *pAchievementMgr) = 0;
	virtual IAchievementMgr *GetAchievementMgr() = 0;

	virtual bool			MapLoadFailed(void) = 0;
	virtual void			SetMapLoadFailed(bool bState) = 0;

	virtual bool			IsLowViolence() = 0;
	virtual const char		*GetMostRecentSaveGame(void) = 0;
	virtual void			SetMostRecentSaveGame(const char *lpszFilename) = 0;

	virtual void			StartXboxExitingProcess() = 0;
	virtual bool			IsSaveInProgress() = 0;
	virtual uintptr_t			OnStorageDeviceAttached(void) = 0;
	virtual void			OnStorageDeviceDetached(void) = 0;

	virtual void			ResetDemoInterpolation(void) = 0;

	// Methods to set/get a gamestats data container so client & server running in same process can send combined data
	virtual void SetGamestatsData(CGamestatsData *pGamestatsData) = 0;
	virtual CGamestatsData *GetGamestatsData() = 0;

#if defined( USE_SDL )
	// we need to pull delta's from the cocoa mgr, the engine vectors this for us
	virtual void GetMouseDelta(int &x, int &y, bool bIgnoreNextMouseDelta = false) = 0;
#endif

	// Sends a key values server command, not allowed from scripts execution
	// Params:
	//	pKeyValues	- key values to be serialized and sent to server
	//				  the pointer is deleted inside the function: pKeyValues->deleteThis()
	virtual void ServerCmdKeyValues(KeyValues *pKeyValues) = 0;

	virtual bool IsSkippingPlayback(void) = 0;
	virtual bool IsLoadingDemo(void) = 0;

	// Returns true if the engine is playing back a "locally recorded" demo, which includes
	// both SourceTV and replay demos, since they're recorded locally (on servers), as opposed
	// to a client recording a demo while connected to a remote server.
	virtual bool IsPlayingDemoALocallyRecordedDemo() = 0;

	// Given the string pBinding which may be bound to a key, 
	//  returns the string name of the key to which this string is bound. Returns NULL if no such binding exists
	// Unlike Key_LookupBinding, leading '+' characters are not stripped from bindings.
	virtual	const char			*Key_LookupBindingExact(const char *pBinding) = 0;

	virtual void				AddPhonemeFile(const char *pszPhonemeFile) = 0;

};
//class IVEngineClient : public IVEngineClient013
//{
//public:
//	virtual uintptr_t GetProtocolVersion() = 0;
//	virtual bool IsWindowedMode() = 0;
//
//	// Flash the window (os specific)
//	virtual void	FlashWindow() = 0;
//
//	// Client version from the steam.inf, this will be compared to the GC version
//	virtual int GetClientVersion() const = 0; // engines build
//
//	// Is App Active 
//	virtual bool IsActiveApp() = 0;
//
//	virtual void DisconnectInternal() = 0;
//
//	virtual int GetInstancesRunningCount() = 0;
//
//	int	GetLocalPlayer() {
//		using GetLocalPlayerFn = int(__fastcall *)(void*);
//		auto GetLocalPlayer = vFunc<GetLocalPlayerFn>(this, engine::idx_GetLocalPlayer);
//		if (!GetLocalPlayer)
//		{
//			std::cout << "GetLocalPlayer failed" << std::endl;
//			return 0;
//		}
//		return GetLocalPlayer(this);
//	}
//
//};

class IVEngineClient
{
public:
	int GetLocalPlayer()
	{
		return vFunc<int(__fastcall*)(void*)>(this, engine::idx_GetLocalPlayer)(this);
	}
};