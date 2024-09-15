class DEF__Starting_Point_MilitaryTents_DE extends GameLabsLiveIndicator
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
        _eventPictogram = "campground"
        _eventDisplayName = "Military tents"
#endif
        super.EEInit(); 
        }
}