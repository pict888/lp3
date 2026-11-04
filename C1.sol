// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

contract BankAccount {

    mapping(address => uint) public balances;

    // Deposit Ether
    function deposit() public payable {
        require(msg.value > 0, "Enter valid amount");

        balances[msg.sender] += msg.value;
    }

    // Withdraw Ether
    function withdraw(uint amount) public {
        require(amount > 0, "Invalid amount");
        require(balances[msg.sender] >= amount, "Insufficient balance");

        balances[msg.sender] -= amount;

        payable(msg.sender).transfer(amount);
    }

    // Display balance
    function showBalance() public view returns (uint) {
        return balances[msg.sender];
    }
}
