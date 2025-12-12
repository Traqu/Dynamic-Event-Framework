class DEF_Land_Boat_Small9_DE extends House
{
    EffectSound     m_Sfx;

    void DEF_Land_Boat_Small9_DE()
    {
        if ( !GetGame().IsDedicatedServer() )
        {
            if(!m_Sfx)
            {
                PlaySoundSetLoop(m_Sfx, "DEF_BoatCreakingDeck_SoundSet", 0.5, 0.5);
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