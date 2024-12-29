class MedicineConfig
{
	[NonSerialized()]
	// Set actual config version (doesn't save to json)
	private string CONFIG_VERSION = "2";

	// Config location
	private const static string MOD_FOLDER = "$profile:\\DynamicEventFramework\\";
	private const static string CONFIG_NAME = "Config.json";

	// Config version
	string ConfigVersion = "";

    float HealthRegenMultiplier = 3.0;

    int AdderallInjectionEffectDuration = 300;
    int AdderallConsumptionEffectDuration = 60;

    int PrimobolanInjectionEffectDuration = 300;
    int PrimobolanEffectStrength = 50;

	// Load config file or create default file if config doesn't exsit
	void Load()
	{
		if (FileExist(MOD_FOLDER + CONFIG_NAME))
		{	// If config exists, load file
			JsonFileLoader<MedicineConfig>.JsonLoadFile(MOD_FOLDER + CONFIG_NAME, this);

			// If version mismatch, backup old version of json before replacing it
			if (ConfigVersion != CONFIG_VERSION)
			{
				JsonFileLoader<MedicineConfig>.JsonSaveFile(MOD_FOLDER + CONFIG_NAME + "_old", this);
			}
			else
			{
				// Config exists and version matches, stop here.
				return;
			}
		}

		// Config file does not exist, create default file
		ConfigVersion = CONFIG_VERSION;

		// Save config
		Save();
	}

	// Save config
	void Save()
	{

		if(!FileExist(MOD_FOLDER))
		{ // If config folder doesn't exist, create it.
			MakeDirectory(MOD_FOLDER);
		}

		// Save JSON config
		JsonFileLoader<MedicineConfig>.JsonSaveFile(MOD_FOLDER + CONFIG_NAME, this);
	}
};

// Save config data
ref MedicineConfig m_MedicineConfig;

// Helper function to return Config data storage object
static MedicineConfig GetMedicineConfig()
{
	if(!m_MedicineConfig && GetGame().IsDedicatedServer())
	{
		Print("[MedicineConfig] Init");
		m_MedicineConfig = new MedicineConfig;
		m_MedicineConfig.Load();
	}

	return m_MedicineConfig;
};