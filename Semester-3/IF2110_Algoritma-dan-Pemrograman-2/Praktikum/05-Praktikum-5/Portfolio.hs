-- Portfolio Management System with Lambda Functions and Higher-Order Functions
module Portfolio where

-- Data type for Person in Portfolio
data Person = Person 
    { name :: String
    , age :: Int  
    , balance :: Double
    } deriving (Show, Eq)

-- Type alias for Portfolio (list of persons)
type Portfolio = [Person]

-- Constructor function using lambda
-- Hint: Kembalikan tipe bentukan Person yang telah terinisialisasi
-- name, age, balance -> Person
makePerson :: String -> Int -> Double -> Person
makePerson = \name -> \age -> \balance -> Person name age balance
-- TODO: Implementasikan fungsi lambda makePerson di sini

-- Transfer function using lambda and higher-order functions
transfer :: String -> String -> Double -> Portfolio -> Portfolio
transfer fromName toName amount portfolio = 
    let updatePerson = \p -> 
            if name p == fromName then p { balance = balance p - amount }
            else if name p == toName then p { balance = balance p + amount }
            else p
    in map updatePerson portfolio
    
-- Withdraw function using lambda
-- name, amount, portfolio -> updated portfolio
--
-- Fungsi withdraw mengurangi saldo (balance) dari person dengan {nama} tertentu sebanyak {amount}
-- 
-- Hint: Gunakan fungsi map dan lambda
withdraw :: String -> Double -> Portfolio -> Portfolio
withdraw n a portfolio = 
    let
        checkPerson = \p ->
            if name p == n then p {balance = balance p - a}
            else p
    in map checkPerson portfolio
    
-- TODO: Implementasikan fungsi withdraw di sini

-- Deposit function using lambda
-- name, amount, portfolio -> updated portfolio
--
-- Fungsi deposit menambah saldo (balance) dari person dengan {nama} tertentu sebanyak {amount}
-- 
-- Hint: Gunakan fungsi map dan lambda
deposit :: String -> Double -> Portfolio -> Portfolio
deposit n a portfolio = 
    let
        checkPerson = \p ->
            if name p == n then p {balance = balance p + a}
            else p
    in map checkPerson portfolio
-- TODO: Implementasikan fungsi deposit di sini

-- Generic sorting function that takes a comparison function as parameter
sortBy :: (Person -> Person -> Ordering) -> Portfolio -> Portfolio
sortBy compareFunc [] = []
sortBy compareFunc (x:xs) = 
    let smaller = sortBy compareFunc (filter (\y -> compareFunc y x == LT) xs)
        equal = filter (\y -> compareFunc y x == EQ) xs  
        greater = sortBy compareFunc (filter (\y -> compareFunc y x == GT) xs)
    in smaller ++ [x] ++ equal ++ greater

-- Sort by name using lambda for comparison
-- Hint: Gunakan compare dan lambda
sortByName :: Portfolio -> Portfolio
sortByName = sortBy (\x y -> compare (head (name x)) (head (name y)))

-- Sort by age using lambda for comparison  
-- Hint: Gunakan compare dan lambda
sortByAge :: Portfolio -> Portfolio
sortByAge = sortBy (\x y -> compare (age x) (age y))


-- Sort by balance using lambda for comparison
-- Hint: Gunakan compare dan lambda
sortByBalance :: Portfolio -> Portfolio
sortByBalance = sortBy (\x y -> compare (balance x) (balance y))
