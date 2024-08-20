class DexamphetamineBagIV_DEF: Inventory_Base
{
    override void SetActions()
    {
        super.SetActions();

        AddAction(ActionGiveDexamphetamineTarget);
        AddAction(ActionGiveDexamphetamineSelf);
    }
};