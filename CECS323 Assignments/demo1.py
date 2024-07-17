# REQUIREMENTS: must use Pip/your IDE to install "sqlalchemy" and "psycopg2".
from sqlalchemy import create_engine, text

# First, some boilerplate.
# These variables represent the different components of a "conection string": a description
# of where a database is, and how to connect to it.
username = "postgres"  # the username and password on the database itself
password = "your_password_here"

host_url = "localhost" # the URL/IP address of the server. 
                       # "localhost" refers to the machine your code is running on.
port = 5432            # the network "port" the database is listening on. this is the default value for postgres.
database_name = "postgres" # the server will have many databases. this is the one we are connecting to.
app_schema = "homework" # this is the "default schema" where we expect our tables to be.

# Initialize a string for the connection settings.
connection_string = f"postgresql+psycopg2://{username}:{password}@{host_url}:{port}/{database_name}"

# Create a SQLAlchemy engine, using the connection string and schema parameters.
# This doesn't do anything yet.
engine = create_engine(connection_string, connect_args={"options": f"-csearch_path={app_schema}"})

# "Open" the connection to the database. Once we leave this "with" block, the connection will close.
with engine.connect() as conn:
    # Prepare a statement to execute on the database. the "text" function means a raw SQL query.
    query = text("select * from customers")
    # Execute the query and retrieve the result.
    res = engine.execute(query)
    # res is an instance of the Result class. It *represents* the returned rows from the query.

    print("All customers:")
    # If we expect one-or-more results, the .all() method retrieves them as a list to iterate through.
    for row in res.all():
        # The "row" variable represents one row at a time from the results. 
        # It *automagically* has fields to match the columns from the selected table.
        print(f"{row.customername} (#{row.customernumber})")
    
    print()
    print()
    query = text("select * from customers where customernumber = 323")
    res = engine.execute(query)
    # If we expect one-result-exactly, the .one() method retrieves that result directly, and throws
    # an exception if none was found.
    try:
        customer = res.one()
        print(f"Customer 323 is: {customer}")
    except:
        print("There is no customer with the number 323")

    print()
    print()
    query = text("select count(*) from customers")
    res = engine.execute(query)
    # If we expect a single scalar value, the .scalar_one() method extracts it directly.
    count = res.scalar_one()
    print(f"There are {count} customers total.")
    
    print()
    print()
    # WARNING: BAD CODE AHEAD. 
    # Attempting a parameterized query, where part of the query comes from user input.
    customer_name = input("Enter a customer name: ")
    query = text(f"select * from customers where customername='{customer_name}'")
    res = engine.execute(query)
    try:
        customer = res.one()
        print(f"The customer named {customer_name} is #{customer.customernumber}")
        
        print("Here are their orders: ")
        query = text(f"select * from orders where customernumber={customer.customernumber}")
        res = engine.execute(query)
        for order in res.all():
            print(f"Order #{order.ordernumber} ({order.status}), placed {order.orderdate}")

    except:
        print(f"There is no customer named {customer_name}")

    
    # Run this code, and enter "Euro+ Shopping Channel" without the quotes. Looks good!
    # Run it again, and enter "Kelly's Gift Shop". Uh oh...
    # Run it again, and enter "' OR 1=1 LIMIT 1;--". Oh boy...

    print()
    print()
    # The correct way to run parameterized queries.
    query = text(f"select * from customers where customername = :name")
    # :name is a parameter to the query. It does not get included directly; it is a placeholder.

    res = engine.execute(query, {"name" : customer_name})
    # When executing the query, the name parameter is replaced by a **sanitized** copy of the
    # customer_name variable.
    try:
        customer = res.one()
        print(f"The customer named {customer_name} is #{customer.customernumber}")

        print()
        status = input("Which order status do you want to view? ")
        print("Here are their orders: ")

        # We can include multiple parameters when needed.
        query = text(f"select * from orders where customernumber = :number and status = :status")
        res = engine.execute(query, {"number" : customer.customernumber, "status": status})

        for order in res.all():
            print(f"Order #{order.ordernumber} ({order.status}), placed {order.orderdate}")
            
    except:
        print(f"There is no customer named {customer_name}")
