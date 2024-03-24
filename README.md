# cdb | Chronicles DB

Column-based in-memory time series database. Built in C++ from scratch.

# TO-DO

- research storage capabilities
- functionality to dynamically read the column types of a table and take that as input. Currently it's string,int,int
- get rid of key-value pair dynamics (since we are not a kv db)

- persist/read the data using shared memory
- add generic table types -> generic data types
- add networking to receive commands
- SIMD instructions
- multithread?
- benchmark performance against other DBs

# DONE

- abstract away maps into hashmap
- functionality to dynamically read the column types of a table and take that as input.
- naively print table

# STRETCH GOALS

- add complex multithreaded capabilities (TBD)
- add in query language
- compression -> serialisation/deserialisation of data for performance?

# PLANNING (do not read)

Databases will process commands. They will also contain the tables and manage 
them. Tables will contain the data. For now, I will keep it simple. As I develop
this application later, there will be need for refactoring - but at the moment
there are incredibly complex components. That being said, I don't want to do
too much in the Database object for now, since it will probably be bloated with
many functionalities in the future.

This will likely need to be incorporated with a database engine. So later on the
DB will be a glorified parser:
It will contain: networking object which will return the commands, a parser object
which will parse the data then send the instructions off to the engine which
will send it off to the tables, which will do the queries?

The internal data structures are current just a long vector - but that will cause a 
lot of issues with large reallocations, and difficulties querying. I believe the 'usual'
method for a TS db is to store everything in time buckets.That will be something to
investigate. Perhaps we could also get aggregate buckets of buckets as well, for even
faster queries, but there are tradeoffs here.

Difficulties:
- Variant data types: store void*? Then we can't do optimizations later on with simd?
- std::string on my machine is 32 bytes, don't really want to std::variant with 4 byte ints
- decided to flyweight pattern: string intern all strings into an integer.
