#include <iostream>
#include <string>
#include <algorithm>

// ==========================================
// 1. ABSTRACTION (Interface Contract)
// Pure abstract class with pure virtual functions
// ==========================================
class CrowdControlCleanser {
public:
    virtual ~CrowdControlCleanser() = default;
    virtual void castUltimate(const std::string& allyTeam) = 0;
};

// ==========================================
// 1. ABSTRACTION & INHERITANCE (Base Class)
// Base class with virtual destructor and overridable methods
// ==========================================
class Hero {
private:
    std::string heroName;
    int level;

public:
    Hero(const std::string& heroName, int level)
        : heroName(heroName), level(level) {}

    virtual ~Hero() = default;

    void move(const std::string& targetLocation) const {
        std::cout << heroName << " moves towards " << targetLocation << ".\n";
    }

    void levelUp() {
        level++;
        std::cout << "⭐ " << heroName << " leveled up to Lv. " << level << "!\n";
    }

    // Default death behavior (virtual to allow overriding)
    virtual void onDeath() {
        std::cout << heroName << " has died. Waiting on base respawn timer...\n";
    }

    std::string getHeroName() const { return heroName; }
    int getLevel() const { return level; }
};

// ==========================================
// 2. INHERITANCE, ENCAPSULATION & POLYMORPHISM
// Diggie inherits from Hero and implements the CC Cleanser interface
// ==========================================
class Diggie : public Hero, public CrowdControlCleanser {
private:
    // ENCAPSULATION: Private member variables
    int hp;
    int maxHp;
    int bombStacks;
    bool isEggForm;
    std::string buildType;

public:
    explicit Diggie(const std::string& buildType)
        : Hero("Diggie", 1),
          hp(2400),
          maxHp(2400),
          bombStacks(3),
          isEggForm(false),
          buildType(buildType) {}

    // ENCAPSULATION: Controlled mutation of HP
    void takeDamage(int damage) {
        if (isEggForm) {
            std::cout << "🛡️ Diggie is in Egg Form! Immune to damage.\n";
            return;
        }

        hp -= damage;
        std::cout << "💥 Diggie takes " << damage << " DMG. Current HP: " 
                  << std::max(0, hp) << "/" << maxHp << "\n";

        if (hp <= 0) {
            hp = 0;
            onDeath(); // Triggers overridden death logic
        }
    }

    // POLYMORPHISM (Method Overriding - Runtime)
    void onDeath() override {
        isEggForm = true;
        std::cout << "🥚 [Passive: Young Again] Diggie enters Egg Form! Running freely around enemies to provide vision.\n";
    }

    // POLYMORPHISM (Method Overloading - Compile-time)
    // Variation 1: Standard bomb
    void plantBomb(const std::string& bushLocation) {
        if (bombStacks > 0) {
            bombStacks--;
            std::cout << "💣 [Skill 1] Auto Alarm Bomb planted at: " << bushLocation 
                      << " (Charges remaining: " << bombStacks << ")\n";
        } else {
            std::cout << "❌ Out of bomb charges!\n";
        }
    }

    // Variation 2: Overloaded signature with tracking delay
    void plantBomb(const std::string& bushLocation, int trackingDelaySeconds) {
        if (bombStacks > 0) {
            bombStacks--;
            std::cout << "💣 [Skill 1] Auto Alarm Bomb planted at " << bushLocation 
                      << " with a " << trackingDelaySeconds << "s chase delay.\n";
        } else {
            std::cout << "❌ Out of bomb charges!\n";
        }
    }

    // ABSTRACTION: Implementing the pure virtual interface function
    void castUltimate(const std::string& allyTeam) override {
        std::cout << "⏰ [Ultimate: Time's Journey] Purged all Crowd Control and applied massive shields to " 
                  << allyTeam << "!\n";
    }

    void respawn() {
        isEggForm = false;
        hp = maxHp;
        std::cout << "🐣 Diggie hatches back to normal bird form at current location with full HP!\n";
    }

    // Getters
    bool getIsEggForm() const { return isEggForm; }
    std::string getBuildType() const { return buildType; }
};

// ==========================================
// 3. EXECUTION
// ==========================================
int main() {
    std::cout << "=== 1. OBJECT INSTANTIATION ===\n";
    Diggie roamerDiggie("Tank Support Build");
    std::cout << "Hero: " << roamerDiggie.getHeroName() 
              << " | Build: " << roamerDiggie.getBuildType() << "\n";

    std::cout << "\n=== 2. INHERITANCE ===\n";
    roamerDiggie.move("River Mid Bush");
    roamerDiggie.levelUp();

    std::cout << "\n=== 3. POLYMORPHISM (Method Overloading) ===\n";
    roamerDiggie.plantBomb("Enemy Blue Buff Bush");
    roamerDiggie.plantBomb("Dragon Pit Bush", 3);

    std::cout << "\n=== 4. ABSTRACTION (Interface Call) ===\n";
    roamerDiggie.castUltimate("Allies in Range");

    std::cout << "\n=== 5. ENCAPSULATION & METHOD OVERRIDING ===\n";
    roamerDiggie.takeDamage(1000);
    roamerDiggie.takeDamage(1600); // Triggers onDeath() -> Egg Form

    // Testing behavior in Egg Form
    roamerDiggie.takeDamage(500); // Immune
    roamerDiggie.move("Enemy Base to scout vision");

    roamerDiggie.respawn();
    

    return 0;
}