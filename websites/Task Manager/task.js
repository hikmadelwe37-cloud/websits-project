const taskForm = document.getElementById('task-form');
const taskTitleInput = document.getElementById('task-title');
const taskPriorityInput = document.getElementById('task-priority');
const taskList = document.getElementById('task-list');
const filterBtns = document.querySelectorAll('.filter-btn');

// Get tasks from local storage or initialize empty array
let tasks = JSON.parse(localStorage.getItem('tasks')) || [];
let currentFilter = 'all';

// Add task event
taskForm.addEventListener('submit', function(e) {
    e.preventDefault();

    if(taskTitleInput.value.trim() === '') {
        alert('Please enter a task title');
        return;
    }

    const newTask = {
        id: Date.now(),
        title: taskTitleInput.value,
        priority: taskPriorityInput.value,
        completed: false
    };

    tasks.push(newTask);
    updateLocalStorage();
    renderTasks();

    taskTitleInput.value = '';
});

// Toggle task completion status
function toggleTask(id) {
    tasks = tasks.map(task => {
        if(task.id === id) {
            return { ...task, completed: !task.completed };
        }
        return task;
    });
    updateLocalStorage();
    renderTasks();
}

// Delete task
function deleteTask(id) {
    tasks = tasks.filter(task => task.id !== id);
    updateLocalStorage();
    renderTasks();
}

// Render tasks to DOM based on filter
function renderTasks() {
    taskList.innerHTML = '';

    const filteredTasks = tasks.filter(task => {
        if(currentFilter === 'pending') return !task.completed;
        if(currentFilter === 'completed') return task.completed;
        return true; // 'all'
    });

    if(filteredTasks.length === 0) {
        taskList.innerHTML = `<p style="text-align: center; color: #777; padding: 15px;">No tasks found.</p>`;
        return;
    }

    filteredTasks.forEach(task => {
        const li = document.createElement('li');
        if(task.completed) li.classList.add('completed');

        li.innerHTML = `
            <div class="task-info">
                <span>${task.title}</span>
                <small>Priority: ${task.priority}</small>
            </div>
            <div class="task-actions">
                <button class="complete-btn" onclick="toggleTask(${task.id})">${task.completed ? 'Undo' : 'Done'}</button>
                <button class="delete-btn" onclick="deleteTask(${task.id})">Delete</button>
            </div>
        `;
        taskList.appendChild(li);
    });
}

// Filter button event listeners
filterBtns.forEach(btn => {
    btn.addEventListener('click', function() {
        filterBtns.forEach(b => b.classList.remove('active'));
        this.classList.add('active');
        currentFilter = this.getAttribute('data-filter');
        renderTasks();
    });
});

// Update Local Storage
function updateLocalStorage() {
    localStorage.setItem('tasks', JSON.stringify(tasks));
}

// Initial load
renderTasks();