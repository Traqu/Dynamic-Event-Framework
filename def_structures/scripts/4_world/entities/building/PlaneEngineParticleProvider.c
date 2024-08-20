class PlaneEngineParticleProvider extends House
{
    Particle m_SmokeTrail;

    void PlaneEngineParticleProvider()
	{
		if ( !GetGame().IsDedicatedServer() )
		{
			m_SmokeTrail = ParticleManager.GetInstance().PlayOnObject(ParticleList.SMOKING_HELI_WRECK, this, Vector(5.15, -2, -3.63));
		}
	}

    override void EEDelete(EntityAI parent)
	{
		if ( !GetGame().IsDedicatedServer() )
		{
			if ( m_SmokeTrail )
				m_SmokeTrail.Stop();
		}
	}
}