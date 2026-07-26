class DEF__Starting_Point_AC130JCrash_DE extends GameLabsLiveIndicator
{
    static bool m_SoundInit = SoundInit();

    static bool SoundInit()
    {
        CrashSoundSets.RegisterSoundSet("DEF_PlaneCrash_Distant_SoundSet");
        return true;
    };

    override string GetSoundSet()
    {
        return "DEF_PlaneCrash_Distant_SoundSet";
    };

};