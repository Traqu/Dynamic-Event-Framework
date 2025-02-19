class DEF_PARTICLE_GRENADE_M18_RED_LOOP_SMOKE_DE extends House
{
    Particle m_Ptc;

    void DEF_PARTICLE_GRENADE_M18_RED_LOOP_SMOKE_DE()
    {
        if ( !GetGame().IsDedicatedServer() )
        {
            m_Ptc = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_M18_RED_LOOP, this, Vector(0.0, 0.0, 0.0));
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