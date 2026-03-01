class ActionMineObsidianChunkCB : ActionContinuousBaseCB
{
	private const float TIME_TO_MINE_OBSIDIAN = 5;

	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(TIME_TO_MINE_OBSIDIAN);
	}
};

class ActionMineObsidianChunk : ActionMineRock
{
	void ActionMineObsidianChunk()
	{
		m_CallbackClass = ActionMineObsidianChunkCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_MINEROCK;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
		m_Text = "#crumbleObsidianChunk";
	}

	override void OnActionInfoUpdate(PlayerBase player, ActionTarget target, ItemBase item)
	{
		m_Text = "#crumbleObsidianChunk";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (player.GetBrokenLegs() == eBrokenLegs.BROKEN_LEGS)
			return false;

		if (!item || item.IsRuined())
			return false;

		ItemBase targetItem = ItemBase.Cast(target.GetObject());
		if (!targetItem)
			return false;

		return targetItem.IsKindOf("Obsidian_Chunk_DEF");
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		ItemBase targetItem = ItemBase.Cast(action_data.m_Target.GetObject());
		if (!targetItem)
			return;

		vector spawnPosition = targetItem.GetPosition();
		int spawnCount = Math.RandomIntInclusive(2, 4);

		for (int i = 0; i < spawnCount; i++)
		{
			vector dropPosition = spawnPosition + Vector(Math.RandomFloatInclusive(-0.1, 0.1), 0, Math.RandomFloatInclusive(-0.1, 0.1));
			ItemBase shard = ItemBase.Cast(GetGame().CreateObjectEx("Obsidian_Shard_DEF", dropPosition, ECE_PLACE_ON_SURFACE));

			if (shard)
				shard.SetQuantity(1);
		}

		if (action_data.m_MainItem)
			action_data.m_MainItem.AddHealth("", "", -10);

		GetGame().ObjectDelete(targetItem);
	}
};
