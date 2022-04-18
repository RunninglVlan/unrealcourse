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
- OMG, all Unreal assets have the same type - UASSET (even imported images), and they all are binary =( (Alright, there's also UMAP)
  - Although assets can be filtered in _Content Browser_, it's impossible to differentiate between them in _File Explorer_
- When you set up [Source Control](https://docs.unrealengine.com/4.27/en-US/Basics/SourceControl/) you can [Diff Against Depot](https://www.unrealengine.com/en-US/blog/diffing-unreal-assets)
  - Unreal will export text version of the asset and diff it using your preferred tool, but even then it sometimes generates text version strange and shows differences when there were none
  - Asset revisions can be diffed through _History_
- [BSP (Binary Space Partitioning) geometry](https://docs.unrealengine.com/4.27/en-US/Basics/Actors/Brushes/) is a tool in Unreal for very basic level design
  - If you select a material and place a Geometry in the scene, it will have that material
  - BSPs interact with each other, there are 2 types of brushes. _Additive_ is like solid, filled-in space. _Subtractive_ is a hollow, carved-out space. You can place additive hollow box and combine it with subtractive boxes to create doors and windows.
  - _Order_ is important and can be changed (To First, To Last)
  - BSPs can also be converted to Static Meshes (SM can also be created from several currently selected BSPs)
  - BSP can be changed in _Brush Editing_ by selecting and moving its specific faces, edges or vertices
- Asset refactoring is difficult in Unreal
  - Renaming asset creates a [redirector](https://docs.unrealengine.com/4.27/en-US/ProductionPipelines/Redirectors/) with the old name (for other assets that still reference it).
  - To get rid of these redirectors and update the references - right click on the folder and _Fix Up Redirectors..._
  - Still this breaks Version Control History...
- To move static meshes in game they need to be [Movable](https://docs.unrealengine.com/5.0/en-US/actor-mobility-in-unreal-engine/)
- For some reason [transform rotation](https://docs.unrealengine.com/4.27/en-US/API/Runtime/Core/Math/FRotator/) values in Unreal don't have XYZ axes, but Roll/Pitch/Yaw axes. And even `FRotator` ctor has a different order for these axes.
- [Material Instances](https://docs.unrealengine.com/4.27/en-US/RenderingAndGraphics/Materials/MaterialInstances/) can be used to have different UV scaling for different surfaces
  - Expose parameters in Material, change them in Instances
- Collision can be [Simple or Complex](https://docs.unrealengine.com/4.27/en-US/InteractiveExperiences/Physics/SimpleVsComplex/)
  - Simple uses primitives like cube, sphere. Complex - trimesh of a given object, so it is expensive.
- Press _Alt_ on a selected object, then move it and it will become a duplicate
