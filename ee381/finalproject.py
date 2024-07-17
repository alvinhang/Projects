import numpy as np
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

# Load the data from CSV using numpy
data = np.genfromtxt('Sales_01_20.csv', delimiter=',', skip_header=1)

# Extract the 'Year' and 'SalePrice' columns (assuming 'Year' is the first column and 'SalePrice' is the second)
years = data[:, 0].astype(int)
sale_prices = data[:, 1]

# Sort the data by 'Year'
sorted_indices = np.argsort(years)
years_sorted = years[sorted_indices]
sale_prices_sorted = sale_prices[sorted_indices]

# Filter data for years 2001 to 2020
filtered_indices = (years_sorted >= 2001) & (years_sorted <= 2020)
years_filtered = years_sorted[filtered_indices]
sale_prices_filtered = sale_prices_sorted[filtered_indices]

# Initialize arrays to store results
unique_years = np.arange(2001, 2021)
means = []
std_devs = []
probabilities = []

# Years to plot and print details for
specific_years = [2001, 2005, 2010, 2015, 2020]

# Calculate mean, standard deviation, and probability for each year
for year in unique_years:
    year_indices = (years_filtered == year)
    year_prices = sale_prices_filtered[year_indices]
    if year_prices.size > 0:
        mean_price = np.mean(year_prices)
        std_price = np.std(year_prices)
        # Probability calculation
        count_in_range = ((year_prices >= 200000) & (year_prices <= 300000)).sum()
        total_count = year_prices.size
        probability = count_in_range / total_count
    else:
        mean_price = 0
        std_price = 0
        probability = 0

    means.append(mean_price)
    std_devs.append(std_price)
    probabilities.append(probability)

    if year in specific_years:
        print(f"Year: {year}")
        print(f"Mean Sale Price: ${mean_price:.2f}")
        print(f"Standard Deviation: ${std_price:.2f}")
        print(f"Probability of Sale Price between $200,000 and $300,000: {probability:.4f}")
        print("")  # Adds an empty line for better readability

# Plotting the results
fig, axs = plt.subplots(3, 1, figsize=(8, 12))

# Plot means and format the y-axis to show 'hundreds of thousands'
axs[0].bar(unique_years, means, color='blue')
axs[0].set_title('Yearly Mean Sale Price')
axs[0].set_xlabel('Year')
axs[0].set_ylabel('Mean Sale Price (in $100k)')
axs[0].set_xticks(specific_years)  # Set specific years as x-ticks
axs[0].yaxis.set_major_formatter(ticker.FuncFormatter(lambda x, pos: f'{x / 1e5:.0f}'))  # Format y-tick labels

# Plot standard deviations
axs[1].bar(unique_years, std_devs, color='red')
axs[1].set_title('Yearly Standard Deviation of Sale Prices')
axs[1].set_xlabel('Year')
axs[1].set_ylabel('Standard Deviation ($)')
axs[1].set_xticks(specific_years)  # Set specific years as x-ticks

# Plot probabilities
axs[2].bar(unique_years, probabilities, color='green')
axs[2].set_title('Probability of Sale Price between 200,000 and 300,000')
axs[2].set_xlabel('Year')
axs[2].set_ylabel('Probability')
axs[2].set_xticks(specific_years)  # Set specific years as x-ticks

fig.subplots_adjust(hspace=0.5)

plt.tight_layout()
plt.show()
