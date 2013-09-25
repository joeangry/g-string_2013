#ifndef C_GSTRING_PLAYER_H
#define C_GSTRING_PLAYER_H

#include "c_basehlplayer.h"

class C_MuzzleflashEffect;

class C_GstringPlayer : public C_BaseHLPlayer
{
	DECLARE_CLASS( C_GstringPlayer, C_BaseHLPlayer );
	DECLARE_CLIENTCLASS();

public:
	C_GstringPlayer();
	~C_GstringPlayer();

	bool IsNightvisionActive() const;
	float GetNightvisionFraction() const;

	virtual void OnDataChanged( DataUpdateType_t updateType );

	virtual void ClientThink();

	virtual void OverrideView( CViewSetup *pSetup );

	virtual void ProcessMuzzleFlashEvent();
	virtual void UpdateFlashlight();


protected:

private:
	CNetworkVar( bool, m_bNightvisionActive );

	float m_flNightvisionFraction;

	float m_flMuzzleFlashTime;
	float m_flMuzzleFlashDuration;
	C_MuzzleflashEffect *m_pMuzzleFlashEffect;

};

inline C_GstringPlayer *ToGstringPlayer( C_BaseEntity *pPlayer )
{
	return assert_cast< C_GstringPlayer* >( pPlayer );
}

inline C_GstringPlayer *LocalGstringPlayer()
{
	return ToGstringPlayer( C_BasePlayer::GetLocalPlayer() );
}

#endif