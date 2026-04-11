---
cssclasses:
  - callouts-outlined
  - dashboard
---
Tampilkan data nomor akun, nama cabang, aset cabang, dan saldo akun dari akun dengan saldo di atas $500 serta berada di cabang dengan nilai aset di atas $1,000,000 dan nama cabang diakhiri huruf ‘k’.
```sql
SELECT
	a.account_number,
	a.branch_name,
	b.assets,
	a.balance
FROM
	account as a,
	JOIN branch b 
	ON a.branch_name = b.branch_name
WHERE
	a.balance > 500
	AND b.assets > 1000000
	AND b.branch_name LIKE '%k';
```

```sql
SELECT
	a.account_number,
	a.branch_name,
	b.assets,
	a.balance
FROM
	account as a,
	NATURAL JOIN branch b 
WHERE
	a.balance > 500
	AND b.assets > 1000000
	AND b.branch_name LIKE '%k';
```

Tampilkan data nomor akun dan perkiraan nilai saldo yang baru (dengan nama column ‘pred_balance’) dari seluruh akun di cabang ‘Uptown’ jika akun dengan saldo minimum $5.000 diberikan bonus sebesar 1%.

```sql
SELECT
	account_number,
	1.01 * balance as pred_balance
FROM
	account
WHERE
	branch_name = 'Uptown'
	AND balance >= 5000
UNION
SELECT
	account_number,
	balance as pred_balance
FROM
	account
WHERE
	branch_name = 'Uptown'
	AND balance < 5000;
```


Tampilkan data nama pelanggan, nomor akun, nilai saldo, kota domisili pelanggan diurutkan berdasarkan nilai saldo dari nilai terbesar ke terkecil. Kemudian untuk akun dengan nilai saldo yang sama diurutkan berdasarkan nomor akun dan nama pelanggan.
```sql
SELECT
	c.customer-name
	a.account-number
	a.balance
	c.customer-city
FROM
	customer as c,
	NATURAL JOIN depositor as d
	NATURAL JOIN account as a
ORDER BY
	a.balance DESC,
	a.account-number ASC,
	c-customer-name ASC;
```

Tampilkan data nama cabang, nilai pinjaman terkecil, nilai pinjaman terbesar, nilai rata-rata pinjaman di cabang tsb, jumlah nilai total pinjaman di cabang tsb, dan banyaknya pinjaman yang dikeluarkan di cabang tsb. Yang perlu ditampilkan hanya cabang dengan banyaknya pinjaman di cabang tsb minimal dua.

```sql
SELECT
	b.branch-name,
	min(l.amount) as min_loan,
	max(l.amount) as max_loan,
	avg(l.amount) as avg_loan,
	sum(l.amount) as sum_loan,
	total(l.loan-number) as total_loan
FROM
	branch as b 
	NATURAL JOIN loan as l
GROUP BY
	branch-name
HAVING
	COUNT(loan_number) >= 2;
```

Tampilkan di kota mana saja customer yang memiliki loan dengan nilai lebih besar dari $1000 tinggal.

```sql
SELECT DISTINCT
	customer_city
FROM
	customer
	NATURAL JOIN borrower
	NATURAL JOIN loan
WHERE
	amount > 1000
```

Tampilkan pasangan nama cabang bank (branch_name1, branch_name2) yang berlokasi di kota yang sama, dan paling tidak salah satunya memiliki aset di atas 2.000.000.000. Pastikan setiap pasangan hanya muncul satu kali.
```sql
SELECT
	b1.branch-name
	b2.branch-name
FROM
	branch as b1 
	JOIN branch as b2
	ON b1.branch_city = b2.branch_city
WHERE
	b1.branch_name < b2.branch_name
	AND (b1.assets > 2000000000
	OR b2.assets > 2000000000)
```

Tampilkan daftar nama customer yang selain memiliki simpanan (account) juga memiliki pinjaman (loan) pada cabang bank yang sama. Tampilkan juga di cabang mana customer tersebut memiliki simpanan dan pinjaman tersebut.
```sql
SELECT
	d.customer-name
	b.branch-name
FROM
	account as a
	NATURAL JOIN depositor 
	NATURAL JOIN borrower 
	NATURAL JOIN loan as l
WHERE
	a.branch-name = l.branch-name
```

```sql
(SELECT
	customer-name
	branch-name
FROM
	depositor NATURAL JOIN account)

INTERSECT

(SELECT
	customer-name
	branch-name
FROM
	loan NATURAL JOIN borrower)
```

Tampilkan daftar nama cabang yang berada di kota ‘Brooklyn’ yang memiliki total pinjaman di atas 5.000.000.000 namun asetnya di bawah 5.000.000.000.
```sql
SELECT
	b.branch_name
FROM
	branch as b
	NATURAL JOIN loan as l
WHERE
	branch_city = 'Brooklyn'
	AND assets < 5000000000
GROUP BY
	branch_name, assets
HAVING
	SUM(amount) > 5000000000
```

Tampilkan daftar nama customer yang tidak memiliki pinjaman di bank.
```sql
SELECT
	customer_name
FROM
	customer
EXCEPT
SELECT
	customer_name
FROM
	borrower;
```

```sql
SELECT
	customer_name
FROM
	customer
WHERE
	name NOT IN (
		SELECT
			customer_name
		FROM
			borrower
	);
```

```sql
SELECT 
	c.name
FROM
	customer as c
WHERE
	NOT EXISTS (
		SELECT
			1
		FROM
			borrower AS b
		WHERE
			b.customer_name = c.name 
	);
```

Tampilkan data pelanggan (nama, alamat, dan kota) yang memiliki akun dengan saldo tertinggi.
```sql
SELECT DISTINCT
	customer_name
	customer_street
	customer_city
FROM
	customer as c
	NATURAL JOIN depositor as d
	NATURAL JOIN account as a
WHERE
	a.balance = (SELECT MAX(balance) FROM account)
```