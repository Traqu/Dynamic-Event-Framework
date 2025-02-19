class DEF_PARTICLE_BONFIRE_FIRE_DE extends House
{
    Particle        m_Ptc;          //FIRE
    Particle        m_BoundPtc;     //SMOKE
    EffectSound     m_Sfx;
	BonfireLight    m_Light;

    void DEF_PARTICLE_BONFIRE_FIRE_DE()
    {
        if ( !GetGame().IsDedicatedServer() )
        {
            if (!m_Ptc)
            {
                m_Ptc = ParticleManager.GetInstance().PlayOnObject(ParticleList.BONFIRE_FIRE, this, Vector(0.0, 0.0, 0.0));
            }
            if (!m_BoundPtc)
            {
                m_BoundPtc = ParticleManager.GetInstance().PlayOnObject(ParticleList.BONFIRE_SMOKE, this, Vector(0,0,0), Vector(0,0,0), true);
            }
            if(!m_Sfx)
            {
                PlaySoundSetLoop(m_Sfx, "HeavyFire_SoundSet", 1.0, 2.0);
            }
            if (!m_Light)
            {
                m_Light = BonfireLight.Cast(ScriptedLightBase.CreateLight(BonfireLight, Vector(0,0,0), 1));
                m_Light.AttachOnObject(this);
                m_Light.FadeBrightnessTo(m_Light.m_FireBrightness, 0);
                m_Light.FadeRadiusTo(m_Light.m_FireRadius, 0);
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