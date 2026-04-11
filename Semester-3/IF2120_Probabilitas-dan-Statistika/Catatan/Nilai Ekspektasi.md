# Rataan (Nilai Ekspektasi)
> **Definisi**: Rataan atau **nilai ekspektasi** ($\mu$) dari sebuah variabel random X adalah ukuran tendensi sentral dari distribusi variabel tersebut. Ini adalah rata-rata tertimbang dari semua nilai yang mungkin, di mana bobotnya adalah peluang dari setiap nilai.

-   Untuk variabel random **diskrit**:    
$$
\mu = E(X) = \sum_{x} x \cdot f(x)
$$

-   Untuk variabel random **kontinu**:
$$
\mu = E(X) = \int_{-\infty}^{\infty} x \cdot f(x) \,dx
$$

Nilai ekspektasi juga dapat dihitung untuk fungsi dari variabel random, misalnya `g(X,Y)`.
-   **Diskrit**: 
$$
\mu_{g(X,Y)} = E[g(X,Y)] = \sum_{x}\sum_{y} g(x,y)f(x,y)
$$

-   **Kontinu**: 
$$
\mu_{g(X,Y)} = E[g(X,Y)] = \int_{-\infty}^{\infty}\int_{-\infty}^{\infty} g(x,y)f(x,y) \,dx\,dy
$$

# Variansi
> **Definisi**: Variansi ($\sigma^2$) mengukur seberapa tersebar (spread) data dalam suatu distribusi dari nilai rata-ratanya. Variansi yang tinggi menunjukkan data yang sangat tersebar, sedangkan variansi rendah menunjukkan data yang cenderung dekat dengan rata-rata.

Variansi didefinisikan sebagai nilai ekspektasi dari kuadrat selisih antara variabel random dengan rata-ratanya.
-   Untuk variabel random **diskrit**:
$$
\sigma^2 = E[(X-\mu)^2] = \sum_{x} (x-\mu)^2 f(x) 
$$
-   Untuk variabel random **kontinu**:
$$
\sigma^2 = E[(X-\mu)^2] = \int_{-\infty}^{\infty} (x-\mu)^2 f(x) \,dx 
$$

> **Teorema (Rumus Cepat Variansi)**: Variansi juga dapat dihitung dengan rumus yang lebih praktis:
> $$
> \sigma^2 = E(X^2) - \mu^2 = E(X^2) - E(X)^2
> $$

**Simpangan Baku (Standard Deviation)**: Akar kuadrat dari variansi, dinotasikan dengan , juga merupakan ukuran sebaran dan memiliki unit yang sama dengan data aslinya.

# Kovariansi
> **Definisi**: Kovariansi ($\sigma_{XY}$) adalah ukuran yang menunjukkan bagaimana dua variabel random (X dan Y) bergerak bersama-sama.

-   **Kovariansi positif**: Menunjukkan bahwa saat X cenderung naik, Y juga cenderung naik.
-   **Kovariansi negatif**: Menunjukkan bahwa saat X cenderung naik, Y justru cenderung turun.

Misalkan X dan Y adalah variabel random dengan distribusi peluang gabungan f(x, y). Kovariansi dari X dan Y adalah
- Untuk variabel random **diskrit**
$$
\sigma_{xy} = E[(X - \mu_x)(Y - \mu_{y})] = \sum_x \sum_y (x - \mu_x)(y - \mu_y) f(x,y)
$$

- Untuk variabel random **kontinu**
$$
\sigma_{xy} = E[(X - \mu_x)(Y - \mu_{y})] = \int_{-\infty}^{\infty} \int_{-\infty}^{\infty} (x - \mu_x)(y - \mu_y) f(x,y) \ dx \ dy
$$

> **Teorema (Rumus Cepat Kovariansi)**:
> $$
> \sigma_{XY} = E(XY) - \mu_X \mu_Y
> $$

# Koefisien Korelasi
> **Definisi**: Koefisien korelasi ($\rho_{XY}$) adalah versi standar dari kovariansi. Nilainya selalu berada di antara -1 dan 1, sehingga lebih mudah diinterpretasikan.

-   $\rho_{XY} = 1$: Korelasi linear positif sempurna.
-   $\rho_{XY} = -1$: Korelasi linear negatif sempurna.
-   $\rho_{XY} = 0$: Tidak ada korelasi linear.

Rumusnya adalah:
$$ \rho_{XY} = \frac{\sigma_{XY}}{\sigma_X \sigma_Y} $$

# Rataan dari Kombinasi Linear
> **Teorema**: Jika $a$ dan $b$ adalah konstanta:
> 1. $E(aX + b) = aE(X) + b$
> 2. $E[g(X) \pm h(X)] = E[g(X)] \pm E[h(X)]$
> 3. $E[g(X,Y) \pm h(X,Y)] = E[g(X,Y)] \pm E[h(X,Y)]$

> **Teorema**: Jika X dan Y adalah variabel random yang **saling bebas**:
> $$
> E(XY) = E(X)E(Y)
> $$

# Variansi dari Kombinasi Linear
> **Teorema**: Jika $a$ dan $b$ adalah konstanta, dan X serta Y adalah variabel random:
> 1. $\sigma^2_{aX+b} = a^2 \sigma^2_X$
> 2. $\sigma^2_{aX+bY} = a^2 \sigma^2_X + b^2 \sigma^2_Y + 2ab\sigma_{XY}$

# Teorema Chebyshev
> **Teorema Chebyshev**: Teorema ini memberikan batas bawah (lower bound) untuk peluang sebuah variabel random akan berada dalam jarak $k$ simpangan baku dari rata-ratanya, **tanpa memandang bentuk distribusinya**.

Rumusnya adalah:
$$ P(\mu - k\sigma < X < \mu + k\sigma) \ge 1 - \frac{1}{k^2} $$

Ini sangat berguna ketika kita tidak mengetahui distribusi dari data, karena kita tetap bisa membuat estimasi tentang probabilitasnya.