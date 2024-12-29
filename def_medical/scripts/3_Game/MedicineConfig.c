class MedicineConfig
{
	static const string CONFIG_VERSION = "2";

	private const static string MOD_FOLDER = "$profile:\\DynamicEventFramework\\";
	private const static string CONFIG_PATH = MOD_FOLDER + "Config.json";

	// Config version
	string ConfigVersion = "";

    float HealthRegenMultiplier = 3.0;

    int AdderallInjectionEffectDuration = 300;
    int AdderallConsumptionEffectDuration = 60;

    int PrimobolanInjectionEffectDuration = 300;
    int PrimobolanEffectStrength = 50;

	void Load()
	{
		if (FileExist(CONFIG_PATH))
		{
			JsonFileLoader<MedicineConfig>.JsonLoadFile(CONFIG_PATH, this);

			if (ConfigVersion != CONFIG_VERSION)
			{
				JsonFileLoader<MedicineConfig>.JsonSaveFile(CONFIG_PATH + "_old", this);
			}
			ConfigVersion = CONFIG_VERSION;
		}
		Save();
	}

	void Save()
	{
		MakeDirectory(MOD_FOLDER);
		JsonFileLoader<MedicineConfig>.JsonSaveFile(CONFIG_PATH, this);
	}
};

ref MedicineConfig m_MedicineConfig;
static MedicineConfig GetMedicineConfig()
{
	if (!m_MedicineConfig && GetGame().IsDedicatedServer())
	{
		Print("[MedicineConfig] Init");
		m_MedicineConfig = new MedicineConfig;
		m_MedicineConfig.Load();
	}
	return m_MedicineConfig;
};