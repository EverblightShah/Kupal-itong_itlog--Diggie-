# ==========================================
# 1. ABSTRACTION (Interface Contract)
# Implemented without abc by raising NotImplementedError
# ==========================================
class CrowdControlCleanser:
    def cast_ultimate(self, ally_team: str) -> None:
        raise NotImplementedError("Subclasses must implement cast_ultimate")


# ==========================================
# 1. ABSTRACTION & INHERITANCE (Base Class)
# Shared blueprint for general hero mechanics.
# ==========================================
class Hero:
    def __init__(self, hero_name: str, level: int):
        self._hero_name = hero_name
        self._level = level

    def move(self, target_location: str) -> None:
        print(f"{self._hero_name} moves towards {target_location}.")

    def level_up(self) -> None:
        self._level += 1
        print(f"⭐ {self._hero_name} leveled up to Lv. {self._level}!")

    # Default death behavior (overridden by Diggie)
    def on_death(self) -> None:
        print(f"{self._hero_name} has died. Waiting on base respawn timer...")

    @property
    def hero_name(self) -> str:
        return self._hero_name

    @property
    def level(self) -> int:
        return self._level


# ==========================================
# 2. INHERITANCE, ENCAPSULATION & POLYMORPHISM
# Diggie inherits from Hero and implements the CC Cleanser interface.
# ==========================================
class Diggie(Hero, CrowdControlCleanser):
    def __init__(self, build_type: str):
        super().__init__(hero_name="Diggie", level=1)
        # ENCAPSULATION: Double leading underscores invoke name mangling (private)
        self.__build_type = build_type
        self.__max_hp = 2400
        self.__hp = self.__max_hp
        self.__bomb_stacks = 3
        self.__is_egg_form = False

    # ENCAPSULATION: Controlled mutation of HP
    def take_damage(self, damage: int) -> None:
        if self.__is_egg_form:
            print("🛡️ Diggie is in Egg Form! Immune to damage.")
            return

        self.__hp -= damage
        print(
            f"💥 Diggie takes {damage} DMG. Current HP: {max(0, self.__hp)}/{self.__max_hp}"
        )

        if self.__hp <= 0:
            self.__hp = 0
            self.on_death()  # Triggers overridden death logic

    # POLYMORPHISM (Method Overriding - Runtime)
    # Replaces default Hero on_death with the Egg Form passive
    def on_death(self) -> None:
        self.__is_egg_form = True
        print(
            "🥚 [Passive: Young Again] Diggie enters Egg Form! Running freely around enemies to provide vision."
        )

    # POLYMORPHISM (Method Overloading Pattern)
    # Handled via default parameter assignment
    def plant_bomb(
        self, bush_location: str, tracking_delay_seconds: int | None = None
    ) -> None:
        if self.__bomb_stacks <= 0:
            print("❌ Out of bomb charges!")
            return

        self.__bomb_stacks -= 1
        if tracking_delay_seconds is None:
            print(
                f"💣 [Skill 1] Auto Alarm Bomb planted at: {bush_location} (Charges remaining: {self.__bomb_stacks})"
            )
        else:
            print(
                f"💣 [Skill 1] Auto Alarm Bomb planted at {bush_location} with a {tracking_delay_seconds}s chase delay."
            )

    # ABSTRACTION: Implementing the interface contract
    def cast_ultimate(self, ally_team: str) -> None:
        print(
            f"⏰ [Ultimate: Time's Journey] Purged all Crowd Control and applied massive shields to {ally_team}!"
        )

    def respawn(self) -> None:
        self.__is_egg_form = False
        self.__hp = self.__max_hp
        print(
            "🐣 Diggie hatches back to normal bird form at current location with full HP!"
        )

    # Encapsulated Getters
    @property
    def is_egg_form(self) -> bool:
        return self.__is_egg_form

    @property
    def build_type(self) -> str:
        return self.__build_type


# ==========================================
# 3. EXECUTION BLOCK
# ==========================================
if __name__ == "__main__":
    print("=== 1. OBJECT INSTANTIATION ===")
    roamer_diggie = Diggie("Tank Support Build")
    print(
        f"Hero: {roamer_diggie.hero_name} | Build: {roamer_diggie.build_type}"
    )

    print("\n=== 2. INHERITANCE ===")
    roamer_diggie.move("River Mid Bush")
    roamer_diggie.level_up()

    print("\n=== 3. POLYMORPHISM (Method Overloading Pattern) ===")
    roamer_diggie.plant_bomb("Enemy Blue Buff Bush")
    roamer_diggie.plant_bomb("Dragon Pit Bush", tracking_delay_seconds=3)

    print("\n=== 4. ABSTRACTION (Interface Call) ===")
    roamer_diggie.cast_ultimate("Allies in Range")

    print("\n=== 5. ENCAPSULATION & METHOD OVERRIDING ===")
    roamer_diggie.take_damage(1000)
    roamer_diggie.take_damage(1600)  # Triggers on_death -> Egg Form

    # Testing behavior in Egg Form
    roamer_diggie.take_damage(500)  # Immune
    roamer_diggie.move("Enemy Base to scout vision")

    roamer_diggie.respawn()