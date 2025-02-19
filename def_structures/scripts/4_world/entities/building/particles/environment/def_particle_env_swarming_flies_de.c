class DEF_PARTICLE_ENV_SWARMING_FLIES_DE extends House
{
    Particle        m_Ptc;
    EffectSound     m_Sfx;

    void DEF_PARTICLE_ENV_SWARMING_FLIES_DE()
    {
        if (!GetGame().IsDedicatedServer())
        {
            if (!m_Ptc)
            {
                m_Ptc = ParticleManager.GetInstance().PlayOnObject(ParticleList.ENV_SWARMING_FLIES, this, Vector(0.0, 0.0, 0.0));
            }
            if (!m_Sfx)
            {
                PlaySoundSetLoop(m_Sfx, "Flies_SoundSet", 1.0, 1.0);
            }
        }
    }

    override void EEDelete(EntityAI parent)
    {
        if (!GetGame().IsDedicatedServer())
        {
            if (m_Ptc)
            {
                m_Ptc.Stop();
            }
            if (m_Sfx)
            {
                StopSoundSet(m_Sfx);
            }
        }
    }
};