public class SummonedMonster implements ISummoned {
    private Monster monster;
    private boolean isFaceUp;
    private boolean isAttacking;

    public SummonedMonster(Monster m, boolean faceUp, boolean attackPos) {
        this.monster = m;
        this.isFaceUp = faceUp;
        this.isAttacking = attackPos;
    }

    public boolean flip() {
    // Mengubah kondisi kartu dari tertutup menjadi terbuka kemudian mengembalikan true. Bila kartu
    // sudah dalam keadaan terbuka, tidak terjadi apa-apa dan mengembalikan false
        if (this.isFaceUp) {
            return false;
        } else {
            this.isFaceUp = true;
            return true;
        }
    }

    public void rotate() {
    // Mengubah posisi kartu dari menyerang ke bertahan atau sebaliknya.
        this.isAttacking = !this.isAttacking;
    }
    
    public int getPositionValue() {
    // Mengembalikan nilai attack jika posisi kartu menyerang. Mengembalikan nilai defense jika
    // posisi kartu bertahan.
        if (this.isAttacking) {
            return this.monster.getAttackValue();
        } else {
            return this.monster.getDefenseValue();
        }
    }

    @Override
    public void render() {
        String msg = "Monster ";
        msg += this.monster.getName();
        msg += " dalam keadaan ";
        if (this.isFaceUp) {
            msg += "terbuka";
        } else {
            msg += "tertutup";
        }
        msg += " dengan posisi ";
        if (this.isAttacking) {
            msg += "menyerang";
        } else {
            msg += "bertahan";
        }
        System.out.println(msg);
    }
}
