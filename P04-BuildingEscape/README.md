# Notes
## Section 4
Building Escape, 52 Lectures: [86](https://www.udemy.com/course/unrealcourse/learn/lecture/16901268) - [131](https://www.udemy.com/course/unrealcourse/learn/lecture/17707454)

## What's new
- Use _Class Viewer_ to see all the classes and their inheritance chain
- When deleting your Custom Class, make sure that no object in the map has it on it
  - Remove CPP/H in Rider, then restart UE
- Logging:
  - `UE_LOG(LogTemp, Warning, TEXT("Hello!"))` <- `Debug.LogWarning("Hello!")`
  - `UE_LOG(LogTemp, Display, TEXT("%s"), *GetOwner()->GetName())` <- `Debug.Log($"{gameObject.name}")`
    - Formatted string takes FString's pointer to array of TCHAR using `operator*()`
  - Use `Display` for grey colored text, `Warning` for yellow, `Error` for red
- PIE - Play In Editor
- If models were created together, then both of them can be selected and put in the scene
- Use `TextureSample` node to add texture to your `Material`. Material with TextureSample can be created automatically if the texture is dragged into scene actor
- OMG, all Unreal assets have the same type - UASSET (even imported images), and they all are binary =(
  - When you set up [Source Control](https://docs.unrealengine.com/4.27/en-US/Basics/SourceControl/) you can [Diff Against Depot](https://www.unrealengine.com/en-US/blog/diffing-unreal-assets)
  - Unreal will export text version of the asset and diff it using your preferred tool, but even then it sometimes generates text version strange and shows differences when there were none
  - Asset revisions can be diffed through _History_
