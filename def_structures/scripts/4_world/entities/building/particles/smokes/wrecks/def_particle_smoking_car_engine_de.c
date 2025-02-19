class DEF_PARTICLE_SMOKING_CAR_ENGINE_DE extends House
{
    Particle m_Ptc;

    void DEF_PARTICLE_SMOKING_CAR_ENGINE_DE()
    {
        if ( !GetGame().IsDedicatedServer() )
        {
            m_Ptc = ParticleManager.GetInstance().PlayOnObject(ParticleList.SMOKING_CAR_ENGINE, this, Vector(0.0, 0.0, 0.0));
        }
    }

    override void EEDelete(EntityAI parent)
    {
        if ( !GetGame().IsDedicatedServer() )
        {
            if ( m_Ptc )
                m_Ptc.Stop();
        }
    }
};