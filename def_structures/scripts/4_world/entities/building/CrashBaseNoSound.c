//! DEPRECATED
/**
*class CrashBaseNoSound extends CrashBase
*{
*	void CrashBaseNoSound()
*	{
*		if ( !GetGame().IsDedicatedServer() )
*		{
*			m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.SMOKING_HELI_WRECK, this, Vector(5.15, -2, -3.63));
*		}
*	}
*
*    override void RequestSoundEvent()
*    {
*        //! Left empty to so it does not request the sound;  `m_ParticleEfx` is provided through the `CrashBase`.
*    }
*}
*/