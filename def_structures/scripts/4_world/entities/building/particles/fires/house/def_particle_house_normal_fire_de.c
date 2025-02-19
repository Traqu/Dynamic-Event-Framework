class DEF_PARTICLE_HOUSE_SMALL_FIRE_DE extends House
{
    Particle        m_Ptc;          //FIRE
    Particle        m_BoundPtc;     //SMOKE
    EffectSound     m_Sfx;
	FireplaceLight    m_Light;

    void DEF_PARTICLE_HOUSE_SMALL_FIRE_DE()
    {
        if ( !GetGame().IsDedicatedServer() )
        {
            if (!m_Ptc)
            {
                m_Ptc = ParticleManager.GetInstance().PlayOnObject(ParticleList.HOUSE_SMALL_FIRE, this, Vector(0.0, 0.0, 0.0));
            }
            if (!m_BoundPtc)
            {
                m_BoundPtc = ParticleManager.GetInstance().PlayOnObject(ParticleList.HOUSE_SMALL_SMOKE, this, Vector(0,0,0), Vector(0,0,0), true);
            }
            if(!m_Sfx)
            {
                PlaySoundSetLoop(m_Sfx, "HeavyFire_SoundSet", 1.0, 2.0);
            }
            if (!m_Light)
            {
                m_Light = FireplaceLight.Cast(ScriptedLightBase.CreateLight(FireplaceLight, Vector(0,0,0), 1));
                m_Light.AttachOnObject(this);
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
            if (m_BoundPtc)
            {
                m_BoundPtc.Stop();
            }
            if (m_Sfx)
            {
                StopSoundSet(m_Sfx);
            }
            if (m_Light)
            {
			    m_Light.FadeOut();
            }
        }
    }
};