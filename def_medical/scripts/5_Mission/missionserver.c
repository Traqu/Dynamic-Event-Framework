modded class MissionServer
{
    void MissionServer()
    {
        GetRPCManager().AddRPC("DEF_MEDICINE", "GetMedicineServerConfig", this, SingeplayerExecutionType.Server);
    }
    
    override void OnInit()
    {
    	super.OnInit();
    
    	Print("[DynamicEventFramework] OnInit - Loaded config successfully ver. " + GetMedicineConfig().ConfigVersion);
    }
    
    void GetMedicineServerConfig(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        if (type == CallType.Server)
        {
            Print("[DynamicEventFramework] Received medicine config request from " + sender.GetId());
            GetRPCManager().SendRPC("DEF_MEDICINE", "ClientStoreMedicineConfig", new Param1<ref MedicineConfig>(GetMedicineConfig()), true, sender);
        }
    }
};