modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
        super.RegisterActions(actions);
        actions.Insert(ActionGiveDexamphetamineSelf);
        actions.Insert(ActionGiveDexamphetamineTarget);
        actions.Insert(ActionInjectAdderallSelf);
        actions.Insert(ActionInjectAdderallTarget);
        actions.Insert(ActionInjectPrimobolanSelf);
        actions.Insert(ActionInjectPrimobolanTarget);
    }
};