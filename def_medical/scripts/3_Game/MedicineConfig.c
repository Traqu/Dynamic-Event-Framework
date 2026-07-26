class MedicineConfig
{
	static const string CONFIG_VERSION = "1";
	private const static string MOD_FOLDER = "$profile:\\DynamicEventFramework\\";
	private const static string CONFIG_PATH = MOD_FOLDER + "medicine-config.json";

	// Config version
	string ConfigVersion = "";

    float HealthRegenMultiplier = 3.0;

    int AdderallInjectionEffectDuration = 300;
    int AdderallConsumptionEffectDuration = 60;

    int PrimobolanInjectionEffectDuration = 300;
    int PrimobolanEffectStrength = 50;

	void Load()
	{
		if ( FileExist(CONFIG_PATH) )
		{
			JsonFileLoader<MedicineConfig>.JsonLoadFile(CONFIG_PATH, this);

			if (ConfigVersion != CONFIG_VERSION)
			{
				JsonFileLoader<MedicineConfig>.JsonSaveFile(CONFIG_PATH + "_old", this);
			};
			ConfigVersion = CONFIG_VERSION;
		};
		Save();
	};

	void Save()
	{
		MakeDirectory(MOD_FOLDER);
		JsonFileLoader<MedicineConfig>.JsonSaveFile(CONFIG_PATH, this);
	};
};

ref MedicineConfig g_MedicineConfig;
static MedicineConfig GetMedicineConfig()
{
	if (!g_MedicineConfig && GetGame().IsServer())
	{
		Print("[MedicineConfig] Init");
		g_MedicineConfig = new MedicineConfig;
		g_MedicineConfig.Load();
	};
	
	return g_MedicineConfig;
};