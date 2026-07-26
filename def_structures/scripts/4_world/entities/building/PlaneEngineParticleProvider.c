class PlaneEngineParticleProvider extends House
{
	bool m_IsModdedParticles = true;
    Particle m_SmokeTrail;
	

    void PlaneEngineParticleProvider()
	{
		if ( !GetGame().IsDedicatedServer() )
		{
			if ( m_IsModdedParticles )
			{
				m_SmokeTrail = ParticleManager.GetInstance().PlayOnObject(ParticleList.DEF_SMOKING_PLANE_WRECK, this, Vector(5.15, -2.4, -3.63));
			}
			else
			{
				m_SmokeTrail = ParticleManager.GetInstance().PlayOnObject(ParticleList.SMOKING_HELI_WRECK, this, Vector(5.15, -2, -3.63));
			}
		};
	};

    override void EEDelete(EntityAI parent)
	{
		if ( !GetGame().IsDedicatedServer() )
		{
			if ( m_SmokeTrail )
				m_SmokeTrail.Stop();
		};
	};
};