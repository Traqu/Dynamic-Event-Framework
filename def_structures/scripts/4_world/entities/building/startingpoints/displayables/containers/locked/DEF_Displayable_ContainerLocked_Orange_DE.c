// 🟠 Orange Container
class DEF_Displayable_ContainerLocked_Orange_DE : DEF_Displayable_ContainerLocked_Base
{
    override int GetLockCompatibilityType(int doorIdx)
    {
        return 1 << EBuildingLockType.SHIP_CONTAINER_2;
    };
}