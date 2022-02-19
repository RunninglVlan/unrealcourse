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
