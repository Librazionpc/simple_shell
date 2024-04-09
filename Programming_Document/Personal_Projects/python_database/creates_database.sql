-- Scripts that creates the database for BFTWorship

CREATE DATABASE IF NOT EXISTS BFTWorship_db;
CREATE USER IF NOT EXISTS 'bft_worship'@'localhost' IDENTIFIED BY 'bftworship==.';

GRANT ALL PRIVILEGES on BFTWorship_db.* TO 'bft_worship'@'localhost';
GRANT SELECT ON perfomance_schema.* TO 'bft_worship'@'localhost';