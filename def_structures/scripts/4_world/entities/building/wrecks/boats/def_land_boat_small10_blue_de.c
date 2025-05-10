class DEF_Land_Boat_Small10_Blue_DE extends House
{
    EffectSound     m_Sfx;

    void DEF_Land_Boat_Small10_Blue_DE()
    {
        if ( !GetGame().IsDedicatedServer() )
        {
            if(!m_Sfx)
            {
                PlaySoundSetLoop(m_Sfx, "BoatWaves_SoundSet", 1.0, 1.0);
            };
        };
    };

    override void EEDelete(EntityAI parent)
    {
        if (!GetGame().IsDedicatedServer())
        {
            if (m_Sfx)
            {
                StopSoundSet(m_Sfx);
            };
        };
    };
};