class DEF__Starting_Point_Asteroid_DE extends GameLabsLiveIndicator
{
    static bool m_SoundInit = SoundInit();

    static bool SoundInit()
    {
        CrashSoundSets.RegisterSoundSet("DEF_Ordnance_Overhead_Wizz_SoundSet");
        return true;
    };

    override string GetSoundSet()
    {
        return "DEF_Ordnance_Overhead_Wizz_SoundSet";
    };

};