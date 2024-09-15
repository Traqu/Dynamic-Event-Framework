class DEF__Starting_Point_AC130JCrash_DE extends GameLabsLiveIndicator
{
    static bool m_SoundInit = SoundInit();

    static bool SoundInit()
    {
        CrashSoundSets.RegisterSoundSet("PlaneCrash_Distant_SoundSet");
        return true;
    }
	
    override string GetSoundSet()
    {
        return "PlaneCrash_Distant_SoundSet";
    }
    
    override void EEInit()
    {
#ifdef GAMELABS
        _eventPictogram = "plane"
        _eventDisplayName = "Plane crash"
#endif
        super.EEInit(); 
    }
}