// File: DiggieDemo.java

// ==========================================
// 1. ABSTRACTION (Interface Contract)
// Hides all complex debuff math behind a single method contract.
// ==========================================
interface CrowdControlCleanser {
    void castUltimate(String allyTeam);
}

// ==========================================
// 1. ABSTRACTION & INHERITANCE (Base Class)
// Shared blueprint for general hero mechanics.
// ==========================================
abstract class Hero {
    private final String heroName;
    private int level;

    public Hero(String heroName, int level) {
        this.heroName = heroName;
        this.level = level;
    }

    public void move(String targetLocation) {
        System.out.println(heroName + " moves towards " + targetLocation + ".");
    }

    public void levelUp() {
        this.level++;
        System.out.println("⭐ " + heroName + " leveled up to Lv. " + this.level + "!");
    }

    // Default death behavior (overridden by Diggie)
    public void onDeath() {
        System.out.println(heroName + " has died. Waiting on base respawn timer...");
    }

    public String getHeroName() { return heroName; }
    public int getLevel() { return level; }
}

// ==========================================
// 2. INHERITANCE, ENCAPSULATION & POLYMORPHISM
// Diggie inherits from Hero and implements the CC Cleanser interface.
// ==========================================
class DiggieHero extends Hero implements CrowdControlCleanser {
    // ENCAPSULATION: Internal states are private to prevent illegal direct mutation
    private int hp;
    private final int maxHp;
    private int bombStacks;
    private boolean isEggForm;
    private final String buildType;

    // Constructor: Blueprint instantiation
    public DiggieHero(String buildType) {
        super("Diggie", 1);
        this.buildType = buildType;
        this.maxHp = 2400;
        this.hp = this.maxHp;
        this.bombStacks = 3;
        this.isEggForm = false;
    }

    // ENCAPSULATION: Controlled modification of HP
    public void takeDamage(int damage) {
        if (isEggForm) {
            System.out.println("🛡️ Diggie is in Egg Form! Immune to damage.");
            return;
        }

        this.hp -= damage;
        System.out.println("💥 Diggie takes " + damage + " DMG. Current HP: " + Math.max(0, this.hp) + "/" + this.maxHp);
        
        if (this.hp <= 0) {
            this.hp = 0;
            onDeath(); // Triggers overridden death logic
        }
    }

    // POLYMORPHISM (Method Overriding - Runtime)
    // Replaces the standard hero death timer with Diggie's Egg passive
    @Override
    public void onDeath() {
        this.isEggForm = true;
        System.out.println("🥚 [Passive: Young Again] Diggie enters Egg Form! Running freely around enemies to provide vision.");
    }

    // POLYMORPHISM (Method Overloading - Compile-time)
    // Variation 1: Plant standard bomb
    public void plantBomb(String bushLocation) {
        if (bombStacks > 0) {
            bombStacks--;
            System.out.println("💣 [Skill 1] Auto Alarm Bomb planted at: " + bushLocation + " (Charges remaining: " + bombStacks + ")");
        } else {
            System.out.println("❌ Out of bomb charges!");
        }
    }

    // Variation 2: Plant bomb with customized delay parameter
    public void plantBomb(String bushLocation, int trackingDelaySeconds) {
        if (bombStacks > 0) {
            bombStacks--;
            System.out.println("💣 [Skill 1] Auto Alarm Bomb planted at " + bushLocation + " with a " + trackingDelaySeconds + "s chase delay.");
        } else {
            System.out.println("❌ Out of bomb charges!");
        }
    }

    // ABSTRACTION: Implementing the interface method
    @Override
    public void castUltimate(String allyTeam) {
        System.out.println("⏰ [Ultimate: Time's Journey] Purged all Crowd Control and applied massive shields to " + allyTeam + "!");
    }

    public void respawn() {
        this.isEggForm = false;
        this.hp = this.maxHp;
        System.out.println("🐣 Diggie hatches back to normal bird form at current location with full HP!");
    }

    // Encapsulated Getters
    public boolean isEggForm() { return isEggForm; }
    public String getBuildType() { return buildType; }
}

// ==========================================
// 3. EXECUTION CLASS (Creating Objects & Testing)
// ==========================================
public class Diggie {
    public static void main(String[] args) {
        System.out.println("=== 1. OBJECT INSTANTIATION ===");
        DiggieHero roamerDiggie = new DiggieHero("Tank Support Build");
        System.out.println("Hero: " + roamerDiggie.getHeroName() + " | Build: " + roamerDiggie.getBuildType());

        System.out.println("\n=== 2. INHERITANCE ===");
        roamerDiggie.move("River Mid Bush");
        roamerDiggie.levelUp();

        System.out.println("\n=== 3. POLYMORPHISM (Method Overloading) ===");
        roamerDiggie.plantBomb("Enemy Blue Buff Bush");
        roamerDiggie.plantBomb("Dragon Pit Bush", 3);

        System.out.println("\n=== 4. ABSTRACTION (Interface Call) ===");
        roamerDiggie.castUltimate("Allies in Range");

        System.out.println("\n=== 5. ENCAPSULATION & METHOD OVERRIDING ===");
        roamerDiggie.takeDamage(1000);
        roamerDiggie.takeDamage(1600); // Exceeds remaining HP -> triggers Egg Form

        // Testing behavior in Egg Form
        roamerDiggie.takeDamage(500); // Should be immune
        roamerDiggie.move("Enemy Base to scout vision");
        
        roamerDiggie.respawn();
    }
}