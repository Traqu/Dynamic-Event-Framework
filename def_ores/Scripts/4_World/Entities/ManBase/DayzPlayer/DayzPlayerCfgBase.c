modded class ModItemRegisterCallbacks
{
    override void RegisterTwoHanded( DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior )
    {
        super.RegisterTwoHanded( pType, pBehavior );
		
		pType.AddItemInHandsProfileIK("Obsidian_Chunk_DEF", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior,	"dz/anims/anm/player/ik/two_handed/stone.anm");
	};
};