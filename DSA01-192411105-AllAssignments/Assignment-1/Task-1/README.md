# Task 1 – Understand the Problem and Identify the Objects

## 1. Objects, data and behaviour

| Object | Data | Behaviour / responsibility |
|---|---|---|
| SmartCard | card ID, balance in paise | recharge, check balance, deduct fare only when the minimum balance rule is satisfied |
| Passenger | passenger ID, passenger category | identify student/senior-citizen concession eligibility |
| Journey | source zone, destination/farthest zone, hour, date | store journey details and determine the farthest zone and travel time |
| Zone | zone name and zone number | represent Inner, Middle and Outer zones |
| FareTable | base fares, surcharge rate, concession rules | return the correct fare from centralized rules |

These are suitable objects because each represents a real system concept and owns related data and operations.

## 2. Procedural and object-oriented styles

A procedural solution stores balances and fares in variables and uses free functions such as `calculateFare()`, `canTravel()` and `deductFare()`. The programmer must ensure every function follows the same rules. In an OOP solution, `SmartCard`, `Journey` and `FareTable` group related data and behaviour. A private card balance prevents unrelated code from changing it directly.

## 3. OOP principles

- **Encapsulation:** keep the card balance private and modify it only through validated methods.
- **Abstraction:** expose `canTravel()` and `deduct()` without exposing internal balance calculations.
- **Inheritance:** a `StudentPassenger` and `SeniorPassenger` may derive from `Passenger` if they have different concession policies.
- **Polymorphism:** a virtual `concessionPercent()` method can return a category-specific concession.

## 4. Rules and assumptions

1. Base fare is Rs 10, Rs 20 or Rs 30 according to the farthest zone.
2. Peak hours are 08:00–09:59 and 17:00–19:59. Exactly 10:00 and 20:00 are off-peak.
3. Peak surcharge is 20%.
4. A journey is accepted only when the remaining balance is at least Rs 50.
5. A rejected journey must not change the balance.
6. A card balance must never become negative.
7. Student/senior concession percentages must be defined by the metro authority; the supplied scenario does not specify their exact percentages.
8. Store money as integer paise to avoid floating-point rounding.

## Alternative concept and complexity

A procedural version can use a balance variable, fare constants and free functions. Both designs take O(1) time for one fare calculation and O(1) memory per card. The difference is maintainability: with classes, a rule is normally changed in one responsible class; with global variables and free functions, every function that uses the rule must be checked and may need changes. The runtime complexity does not improve merely by using OOP.
