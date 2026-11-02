const balanceEl = document.getElementById('balance');
const totalIncomeEl = document.getElementById('total-income');
const totalExpenseEl = document.getElementById('total-expense');
const transactionList = document.getElementById('transaction-list');
const transactionForm = document.getElementById('transaction-form');
const descriptionInput = document.getElementById('description');
const amountInput = document.getElementById('amount');
const categoryInput = document.getElementById('category');
const filterCategory = document.getElementById('filter-category');

// Get transactions from local storage or initialize empty array
let transactions = JSON.parse(localStorage.getItem('transactions')) || [];

// Add transaction event
transactionForm.addEventListener('submit', function(e) {
    e.preventDefault();

    if(descriptionInput.value.trim() === '' || amountInput.value.trim() === '') {
        alert('Please add a description and amount');
        return;
    }

    const transaction = {
        id: generateID(),
        description: descriptionInput.value,
        amount: +amountInput.value,
        category: categoryInput.value
    };

    transactions.push(transaction);
    updateLocalStorage();
    init();

    descriptionInput.value = '';
    amountInput.value = '';
});

// Generate random ID for transactions
function generateID() {
    return Math.floor(Math.random() * 100000000);
}

// Delete transaction by ID
function removeTransaction(id) {
    transactions = transactions.filter(transaction => transaction.id !== id);
    updateLocalStorage();
    init();
}

// Update balance, income, and expense totals
function updateValues() {
    const amounts = transactions.map(transaction => transaction.amount);
    
    const total = amounts.reduce((acc, item) => (acc += item), 0).toFixed(2);
    
    const income = amounts
        .filter(item => item > 0)
        .reduce((acc, item) => (acc += item), 0)
        .toFixed(2);

    const expense = (
        amounts.filter(item => item < 0).reduce((acc, item) => (acc += item), 0) * -1
    ).toFixed(2);

    balanceEl.innerText = `$${total}`;
    totalIncomeEl.innerText = `$${income}`;
    totalExpenseEl.innerText = `-$${expense}`;
}

// Display transactions in the DOM with filter support
function init() {
    transactionList.innerHTML = '';
    
    const selectedFilter = filterCategory.value;
    
    const filteredTransactions = transactions.filter(transaction => {
        if (selectedFilter === 'All') return true;
        return transaction.category === selectedFilter;
    });

    filteredTransactions.forEach(addTransactionDOM);
    updateValues();
}

// Add transactions to DOM list
function addTransactionDOM(transaction) {
    const sign = transaction.amount < 0 ? '-' : '+';
    const itemClass = transaction.amount < 0 ? 'minus' : 'plus';
    
    const item = document.createElement('li');
    item.classList.add(itemClass);
    
    item.innerHTML = `
        ${transaction.description} <small>(${transaction.category})</small> 
        <span>${sign}$${Math.abs(transaction.amount).toFixed(2)}</span>
        <button class="delete-btn" onclick="removeTransaction(${transaction.id})">x</button>
    `;
    
    transactionList.appendChild(item);
}

// Update Local Storage
function updateLocalStorage() {
    localStorage.setItem('transactions', JSON.stringify(transactions));
}

// Listen for category filter changes
filterCategory.addEventListener('change', init);

// Initial load
init();