modded class MissionServer
{
    void MissionServer()
    {
        GetRPCManager().AddRPC("DEF_MEDICINE", "GetMedicineServerConfig", this, SingeplayerExecutionType.Server);
    };

    override void OnInit()
    {
    	super.OnInit();

    	Print("[DynamicEventFramework] OnInit - Loaded config successfully ver. " + GetMedicineConfig().ConfigVersion);
    };

    void GetMedicineServerConfig(int type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        if (GetGame().IsServer())
        {
            string senderId = "unknown";
            if (sender)
            {
                senderId = sender.GetId();
            }

            Print("[DynamicEventFramework] Received medicine config request from " + senderId);
            GetRPCManager().SendRPC("DEF_MEDICINE", "ClientStoreMedicineConfig", new Param1<ref MedicineConfig>(GetMedicineConfig()), true, sender);
        }
    };
};
