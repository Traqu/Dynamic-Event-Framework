class DEF_PARTICLE_GRENADE_RDG2_WHITE_LOOP_DE extends House
{
    Particle m_Ptc;

    void DEF_PARTICLE_GRENADE_RDG2_WHITE_LOOP_DE()
    {
        if ( !GetGame().IsDedicatedServer() )
        {
            m_Ptc = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_RDG2_WHITE_LOOP, this, Vector(0.0, 0.0, 0.0));
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