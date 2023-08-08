-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Read crime scene reports
SELECT id, description FROM crime_scene_reports
 WHERE street = 'Humphrey Street' and year = 2021 and month = 7 and day = 28;
/*
Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
Interviews were conducted today with three witnesses who were present at the time –
each of their interview transcripts mentions the bakery. */

-- check interviews with the three witnesses
SELECT id, name, transcript FROM interviews
 WHERE year = 2021 AND month = 7 AND day = 28;




/*
| 161 | Ruth    | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away.
                  If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
| 162 | Eugene  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery,
                  I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
| 163 | Raymond | As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
                  In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
                  The thief then asked the person on the other end of the phone to purchase the flight ticket. |
*/

-- check security logs of the bakery

SELECT * FROM bakery_security_logs AS b
 WHERE year = 2021 AND month = 7 AND day = 28
   AND hour = 10
   AND minute BETWEEN 10 AND 30
   AND activity = 'exit';

/* Car 5P2BI95 entered the parking at 9:15 and left at 10:16 */

-- check owner of the car
SELECT * FROM people
  JOIN bakery_security_logs b ON people.license_plate = b.license_plate
 WHERE b.year = 2021 AND b.month = 7 AND b.day = 28
   AND b.hour = 10
   AND b.minute BETWEEN 10 AND 30
   AND b.activity = 'exit';

/*
+--------+---------+----------------+-----------------+---------------+-----+------+-------+-----+------+--------+----------+---------------+
|   id   |  name   |  phone_number  | passport_number | license_plate | id  | year | month | day | hour | minute | activity | license_plate |
+--------+---------+----------------+-----------------+---------------+-----+------+-------+-----+------+--------+----------+---------------+
| 221103 | Vanessa | (725) 555-4692 | 2963008352      | 5P2BI95       | 260 | 2021 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
| 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       | 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
| 243696 | Barry   | (301) 555-4174 | 7526138472      | 6P58WS2       | 262 | 2021 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
| 467400 | Luca    | (389) 555-5198 | 8496433585      | 4328GD8       | 263 | 2021 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
| 398010 | Sofia   | (130) 555-0289 | 1695452385      | G412CB7       | 264 | 2021 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
| 396669 | Iman    | (829) 555-5269 | 7049073643      | L93JTIZ       | 265 | 2021 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
| 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       | 266 | 2021 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
| 560886 | Kelsey  | (499) 555-9472 | 8294398571      | 0NTHK55       | 267 | 2021 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
+--------+---------+----------------+-----------------+---------------+-----+------+-------+-----+------+--------+----------+---------------+
*/

-- check atm transactions

SELECT * FROM atm_transactions a
 WHERE year = 2021 AND month = 7 AND day = 28
   AND atm_location = 'Leggett Street'
   AND transaction_type = 'withdraw';

/*
+-----+----------------+------+-------+-----+----------------+------------------+--------+
| id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
+-----+----------------+------+-------+-----+----------------+------------------+--------+
| 246 | 28500762       | 2021 | 7     | 28  | Leggett Street | withdraw         | 48     |
| 264 | 28296815       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 266 | 76054385       | 2021 | 7     | 28  | Leggett Street | withdraw         | 60     |
| 267 | 49610011       | 2021 | 7     | 28  | Leggett Street | withdraw         | 50     |
| 269 | 16153065       | 2021 | 7     | 28  | Leggett Street | withdraw         | 80     |
| 288 | 25506511       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 313 | 81061156       | 2021 | 7     | 28  | Leggett Street | withdraw         | 30     |
| 336 | 26013199       | 2021 | 7     | 28  | Leggett Street | withdraw         | 35     |
+-----+----------------+------+-------+-----+----------------+------------------+--------+
*/

-- check bank account
SELECT b.account_number, b.person_id, p.name, p.phone_number, p.passport_number
 FROM bank_accounts b
 JOIN people p ON b.person_id = p.id
 WHERE b.account_number in (SELECT a.account_number FROM atm_transactions a
                             WHERE year = 2021 AND month = 7 AND day = 28
                               AND atm_location = 'Leggett Street'
                               AND transaction_type = 'withdraw');

/*
+----------------+-----------+---------+----------------+-----------------+
| account_number | person_id |  name   |  phone_number  | passport_number |
+----------------+-----------+---------+----------------+-----------------+
| 49610011       | 686048    | Bruce   | (367) 555-5533 | 5773159633      |
| 26013199       | 514354    | Diana   | (770) 555-1861 | 3592750733      |
| 16153065       | 458378    | Brooke  | (122) 555-4581 | 4408372428      |
| 28296815       | 395717    | Kenny   | (826) 555-1652 | 9878712108      |
| 25506511       | 396669    | Iman    | (829) 555-5269 | 7049073643      |
| 28500762       | 467400    | Luca    | (389) 555-5198 | 8496433585      |
| 76054385       | 449774    | Taylor  | (286) 555-6063 | 1988161715      |
| 81061156       | 438727    | Benista | (338) 555-6650 | 9586786673      |
+----------------+-----------+---------+----------------+-----------------+
*/

-- Based on bakerly logs, atm_transactions and bank accounts, there are three suspects, Bruce, Iman and Luca


-- check her phone calls, bank accounts and atm_transactions
SELECT c.caller, c.receiver, c.duration, p.id, p.name, p.phone_number, p.passport_number
  FROM phone_calls c
  JOIN people p ON c.caller = p.phone_number
 WHERE p.name in ('Bruce', 'Iman', 'Luca')
   AND c.year = 2021 AND c.month = 7 AND c.day = 28;

/* suspect Bruce made phone calls on that day
+----------------+----------------+----------+--------+-------+----------------+-----------------+
|     caller     |    receiver    | duration |   id   | name  |  phone_number  | passport_number |
+----------------+----------------+----------+--------+-------+----------------+-----------------+
| (367) 555-5533 | (375) 555-8161 | 45       | 686048 | Bruce | (367) 555-5533 | 5773159633      |
| (367) 555-5533 | (344) 555-9601 | 120      | 686048 | Bruce | (367) 555-5533 | 5773159633      |
| (367) 555-5533 | (022) 555-4052 | 241      | 686048 | Bruce | (367) 555-5533 | 5773159633      |
| (367) 555-5533 | (704) 555-5790 | 75       | 686048 | Bruce | (367) 555-5533 | 5773159633      |
+----------------+----------------+----------+--------+-------+----------------+-----------------+
*/

-- check flights
SELECT p.*, f.* FROM passengers p
  JOIN flights f ON f.id = p.flight_id
 WHERE p.passport_number = (SELECT passport_number FROM people
                            WHERE name = 'Bruce');


SELECT pa.*, p.* FROM passengers pa
  JOIN people p ON pa.passport_number = p.passport_number
 WHERE pa.flight_id = 36;

/* passenger and flight information
+-----------+-----------------+------+----+-------------------+------------------------+------+-------+-----+------+--------+
| flight_id | passport_number | seat | id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
+-----------+-----------------+------+----+-------------------+------------------------+------+-------+-----+------+--------+
| 36        | 5773159633      | 4A   | 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |
+-----------+-----------------+------+----+-------------------+------------------------+------+-------+-----+------+--------+

+-----------+-----------------+------+--------+--------+----------------+-----------------+---------------+
| flight_id | passport_number | seat |   id   |  name  |  phone_number  | passport_number | license_plate |
+-----------+-----------------+------+--------+--------+----------------+-----------------+---------------+
| 36        | 7214083635      | 2A   | 953679 | Doris  | (066) 555-9701 | 7214083635      | M51FA04       |
| 36        | 1695452385      | 3B   | 398010 | Sofia  | (130) 555-0289 | 1695452385      | G412CB7       |
| 36        | 5773159633      | 4A   | 686048 | Bruce  | (367) 555-5533 | 5773159633      | 94KL13X       |
| 36        | 1540955065      | 5C   | 651714 | Edward | (328) 555-1152 | 1540955065      | 130LD9Z       |
| 36        | 8294398571      | 6C   | 560886 | Kelsey | (499) 555-9472 | 8294398571      | 0NTHK55       |
| 36        | 1988161715      | 6D   | 449774 | Taylor | (286) 555-6063 | 1988161715      | 1106N58       |
| 36        | 9878712108      | 7A   | 395717 | Kenny  | (826) 555-1652 | 9878712108      | 30G67EN       |
| 36        | 8496433585      | 7B   | 467400 | Luca   | (389) 555-5198 | 8496433585      | 4328GD8       |
+-----------+-----------------+------+--------+--------+----------------+-----------------+---------------+

*/

-- check airports
SELECT * FROM airports
 WHERE id = 4 or id = 8;

/*
+----+--------------+-----------------------------+---------------+
| id | abbreviation |          full_name          |     city      |
+----+--------------+-----------------------------+---------------+
| 4  | LGA          | LaGuardia Airport           | New York City |
| 8  | CSF          | Fiftyville Regional Airport | Fiftyville    |
+----+--------------+-----------------------------+---------------+
*/

-- Check the accomplice
SELECT * FROM people p
 WHERE p.phone_number in (SELECT receiver FROM phone_calls
                           WHERE caller = '(367) 555-5533'
                             AND year = 2021 AND month = 7 AND day = 28);

+--------+---------+----------------+-----------------+---------------+
|   id   |  name   |  phone_number  | passport_number | license_plate |
+--------+---------+----------------+-----------------+---------------+
| 315221 | Gregory | (022) 555-4052 | 3355598951      | V4C670D       |
| 652398 | Carl    | (704) 555-5790 | 7771405611      | 81MZ921       |
| 864400 | Robin   | (375) 555-8161 |                 | 4V16VO0       |
| 985497 | Deborah | (344) 555-9601 | 8714200946      | 10I5658       |
+--------+---------+----------------+-----------------+---------------+

