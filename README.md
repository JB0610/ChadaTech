# 12-Hour and 24-Hour Clock Application

## Project Overview
This application is a clock simulator implemented in C++ that displays time in both 12-hour and 24-hour formats. Users have the flexibility to add hours, minutes, or seconds to the current time and see the updated time in both formats.

### Problem it solves:
In the real world, some regions or individuals prefer the 12-hour clock format, while others use the 24-hour format. This application bridges the gap by allowing users to view the time in both formats simultaneously and understand the relation between them. Additionally, it's an educational tool for those unfamiliar with one of the time formats.

## Reflection

### What did I do particularly well?
- Implemented a clean user interface to interact with the clocks, providing clear options for the user to manipulate the time.
- Ensured that time adjustments (like moving from 59 minutes to the next hour) are handled seamlessly, keeping the integrity of the time displayed.

### Where could I enhance my code?
- The application could benefit from allowing the user to set a custom time rather than just adding hours, minutes, or seconds.
- Implementing a real-time feature where the clock updates every second could make it function more like a real-world clock.
  
### Most Challenging Pieces of Code:
- Handling the transition between hours, minutes, and seconds (especially when a value exceeds its limit) was a challenge. To overcome this, helper functions like `addOneHour()`, `addOneMinute()`, and `addOneSecond()` were implemented to ensure seamless transitions.

### Transferable Skills:
- The ability to format and display time is a universally useful skill, especially in applications that involve scheduling, reminders, or any form of time-tracking.
- User interface design and error handling (like the transition between time units) are skills that can be applied across many projects.

### Maintainability, Readability, and Adaptability:
- Used function decomposition to break down tasks (e.g., `formatTime12()`, `formatTime24()`, `addOneSecond()`, etc.), ensuring each function has a single responsibility.
- Consistent naming conventions and commenting have been used to make the code self-explanatory.
- The modular design allows for easy expansion, such as adding more features or integrating with other systems.
  
