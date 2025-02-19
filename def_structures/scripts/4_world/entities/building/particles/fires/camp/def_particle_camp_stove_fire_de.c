class DEF_PARTICLE_CAMP_STOVE_FIRE_DE extends House
{
    Particle        m_Ptc;          //FIRE
    EffectSound     m_Sfx;
	StoveLight      m_Light;

    void DEF_PARTICLE_CAMP_STOVE_FIRE_DE()
    {
        if ( !GetGame().IsDedicatedServer() )
        {
            if (!m_Ptc)
            {
                m_Ptc = ParticleManager.GetInstance().PlayOnObject(ParticleList.CAMP_STOVE_FIRE, this, Vector(0.0, 0.0, 0.0));
            }
            if(!m_Sfx)
            {
                PlaySoundSetLoop(m_Sfx, "portablegasstove_burn_SoundSet", 1.0, 2.0);
            }
            if (!m_Light)
            {
                m_Light = StoveLight.Cast(ScriptedLightBase.CreateLight(StoveLight, "0 0 0"));
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