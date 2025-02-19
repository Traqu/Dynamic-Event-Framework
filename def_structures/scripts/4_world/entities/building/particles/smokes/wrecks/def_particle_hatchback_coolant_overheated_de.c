class DEF_PARTICLE_HATCHBACK_COOLANT_OVERHEATED_DE extends House
{
    Particle m_Ptc;

    void DEF_PARTICLE_HATCHBACK_COOLANT_OVERHEATED_DE()
    {
        if ( !GetGame().IsDedicatedServer() )
        {
            m_Ptc = ParticleManager.GetInstance().PlayOnObject(ParticleList.HATCHBACK_COOLANT_OVERHEATED, this, Vector(0.0, 0.0, 0.0));
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