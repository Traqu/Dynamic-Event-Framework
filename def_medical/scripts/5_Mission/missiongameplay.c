modded class MissionGameplay
{
	void MissionGameplay()
	{
		GetRPCManager().AddRPC("DEF_MEDICINE", "ClientStoreMedicineConfig", this, SingeplayerExecutionType.Client);
		GetRPCManager().SendRPC("DEF_MEDICINE", "GetMedicineServerConfig");
	}

	void ClientStoreMedicineConfig(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
	{
		if (type == CallType.Client)
		{
			Param1<ref BunkerSchedulerConfig> data;
			if (!ctx.Read(data)) return;

			Print("[DynamicEventFramework] Received medicine config");
			g_MedicineConfig = data.param1;
		}
	}
};