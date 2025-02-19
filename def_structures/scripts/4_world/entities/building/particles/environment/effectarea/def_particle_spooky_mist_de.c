class DEF_PARTICLE_SPOOKY_MIST_DE extends House
{
    Particle m_Ptc;

    void DEF_PARTICLE_SPOOKY_MIST_DE()
    {
        if ( !GetGame().IsDedicatedServer() )
        {
            m_Ptc = ParticleManager.GetInstance().PlayOnObject(ParticleList.SPOOKY_MIST, this, Vector(0.0, 0.0, 0.0));
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