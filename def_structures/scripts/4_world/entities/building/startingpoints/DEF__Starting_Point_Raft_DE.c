class DEF__Starting_Point_Raft_DE extends GameLabsLiveIndicator_Base
{
    static bool m_SoundInit = SoundInit();

    static bool SoundInit()
    {
        CrashSoundSets.RegisterSoundSet("Dummy_Silent_SoundSet");
        return true;
    }
	
    override string GetSoundSet()
    {
        return "Dummy_Silent_SoundSet";
    }

    override void EEInit()
    {
#ifdef GAMELABS
        _eventPictogram = "anchor"
        _eventDisplayName = "Shoal boat"
#endif
        super.EEInit();
#ifdef DIAG
        if ( !GetGame().IsMultiplayer() )
        {
            EffectSound eff = SEffectManager.PlaySound( GetSoundSet(), GetPosition(), 0.1, 0.1 );
            eff.SetAutodestroy(true);
        }
#endif
    }
}