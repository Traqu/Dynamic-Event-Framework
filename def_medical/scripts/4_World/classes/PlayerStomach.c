modded class PlayerStomach
{
    void DEF_RemoveAgentsFromContents(int agentsToRemove)
    {
        if (!agentsToRemove)
            return;

        foreach (StomachItem item : m_StomachContents)
        {
            item.m_Agents = item.m_Agents & ~agentsToRemove;
        };
    };
};