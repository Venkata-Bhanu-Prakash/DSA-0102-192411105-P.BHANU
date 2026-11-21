# Task 6 – Design the Control Structures

## Pseudocode

```text
BEGIN
  READ zone, hour
  IF hour is outside 0..23 OR zone is invalid
    PRINT invalid journey
    STOP this journey
  ENDIF
  SET peak = (hour >= 8 AND hour < 10) OR
             (hour >= 17 AND hour < 20)
  USE SWITCH on zone to select base fare in paise
  IF peak
    ADD 20 percent surcharge using integer arithmetic
  ENDIF
  IF balance - fare >= 5000
    deduct fare
    print fare and balance
  ELSE
    print journey denied
  ENDIF
END
```

Use `switch` for the finite zone choices, `if-else` for validation and balance rules, and `?:` only for a short value selection. A counted `for` loop is suitable when the number of journeys is known; a `while` loop is suitable for continuous gate input; a range-based `for` loop is suitable for a stored collection. An invalid journey can use `continue`. A `switch` with no matching case and no `default` executes no case body.

## Completed TODO program

See `Task6.cpp`. It uses a switch, integer paise and the minimum remaining balance rule. The peak rule treats 10:00 and 20:00 as off-peak because the upper bounds are exclusive.
