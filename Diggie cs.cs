// File: DiggieDemo.cs
using System;

// ==========================================
// 1. ABSTRACTION (Interface Contract)
// Hides all complex debuff math behind a single method contract.
// ==========================================
public interface ICrowdControlCleanser
{
    void CastUltimate(string allyTeam);
}

// ==========================================
// 1. ABSTRACTION & INHERITANCE (Base Class)
// Shared blueprint for general hero mechanics.
// ==========================================
public abstract class Hero
{
    public string HeroName { get; }
    public int Level { get; private set; }

    public Hero(string heroName, int level)
    {
        HeroName = heroName;
        Level = level;
    }

    public void Move(string targetLocation)
    {
        Console.WriteLine($"{HeroName} moves towards {targetLocation}.");
    }

    public void LevelUp()
    {
        Level++;
        Console.WriteLine($"⭐ {HeroName} leveled up to Lv. {Level}!");
    }

    // C# requires 'virtual' explicitly to allow derived classes to override it
    public virtual void OnDeath()
    {
        Console.WriteLine($"{HeroName} has died. Waiting on base respawn timer...");
    }
}

// ==========================================
// 2. INHERITANCE, ENCAPSULATION & POLYMORPHISM
// Diggie inherits from Hero and implements the CC Cleanser interface.
// ==========================================
public class DiggieHero : Hero, ICrowdControlCleanser
{
    // ENCAPSULATION: Internal states are private to prevent illegal direct mutation
    private int hp;
    private readonly int maxHp;
    private int bombStacks;

    // Encapsulated Auto-Properties
    public bool IsEggForm { get; private set; }
    public string BuildType { get; }

    // Constructor: Calls the base class constructor using ': base(...)'
    public DiggieHero(string buildType) : base("Diggie", 1)
    {
        BuildType = buildType;
        maxHp = 2400;
        hp = maxHp;
        bombStacks = 3;
        IsEggForm = false;
    }

    // ENCAPSULATION: Controlled modification of HP
    public void TakeDamage(int damage)
    {
        if (IsEggForm)
        {
            Console.WriteLine("🛡️ Diggie is in Egg Form! Immune to damage.");
            return;
        }

        hp -= damage;
        Console.WriteLine($"💥 Diggie takes {damage} DMG. Current HP: {Math.Max(0, hp)}/{maxHp}");

        if (hp <= 0)
        {
            hp = 0;
            OnDeath(); // Triggers overridden death logic
        }
    }

    // POLYMORPHISM (Method Overriding - Runtime)
    // Replaces the standard hero death timer with Diggie's Egg passive
    public override void OnDeath()
    {
        IsEggForm = true;
        Console.WriteLine("🥚 [Passive: Young Again] Diggie enters Egg Form! Running freely around enemies to provide vision.");
    }

    // POLYMORPHISM (Method Overloading - Compile-time)
    // Variation 1: Plant standard bomb
    public void PlantBomb(string bushLocation)
    {
        if (bombStacks > 0)
        {
            bombStacks--;
            Console.WriteLine($"💣 [Skill 1] Auto Alarm Bomb planted at: {bushLocation} (Charges remaining: {bombStacks})");
        }
        else
        {
            Console.WriteLine("❌ Out of bomb charges!");
        }
    }

    // Variation 2: Plant bomb with customized delay parameter
    public void PlantBomb(string bushLocation, int trackingDelaySeconds)
    {
        if (bombStacks > 0)
        {
            bombStacks--;
            Console.WriteLine($"💣 [Skill 1] Auto Alarm Bomb planted at {bushLocation} with a {trackingDelaySeconds}s chase delay.");
        }
        else
        {
            Console.WriteLine("❌ Out of bomb charges!");
        }
    }

    // ABSTRACTION: Implementing the interface method
    public void CastUltimate(string allyTeam)
    {
        Console.WriteLine($"⏰ [Ultimate: Time's Journey] Purged all Crowd Control and applied massive shields to {allyTeam}!");
    }

    public void Respawn()
    {
        IsEggForm = false;
        hp = maxHp;
        Console.WriteLine("🐣 Diggie hatches back to normal bird form at current location with full HP!");
    }
}

// ==========================================
// 3. EXECUTION CLASS (Creating Objects & Testing)
// ==========================================
public class Program
{
    public static void Main(string[] args)
    {
        Console.WriteLine("=== 1. OBJECT INSTANTIATION ===");
        DiggieHero roamerDiggie = new DiggieHero("Tank Support Build");
        Console.WriteLine($"Hero: {roamerDiggie.HeroName} | Build: {roamerDiggie.BuildType}");

        Console.WriteLine("\n=== 2. INHERITANCE ===");
        roamerDiggie.Move("River Mid Bush");
        roamerDiggie.LevelUp();

        Console.WriteLine("\n=== 3. POLYMORPHISM (Method Overloading) ===");
        roamerDiggie.PlantBomb("Enemy Blue Buff Bush");
        roamerDiggie.PlantBomb("Dragon Pit Bush", 3);

        Console.WriteLine("\n=== 4. ABSTRACTION (Interface Call) ===");
        roamerDiggie.CastUltimate("Allies in Range");

        Console.WriteLine("\n=== 5. ENCAPSULATION & METHOD OVERRIDING ===");
        roamerDiggie.TakeDamage(1000);
        roamerDiggie.TakeDamage(1600); // Exceeds remaining HP -> triggers Egg Form

        // Testing behavior in Egg Form
        roamerDiggie.TakeDamage(500); // Should be immune
        roamerDiggie.Move("Enemy Base to scout vision");

        roamerDiggie.Respawn();
    }
}