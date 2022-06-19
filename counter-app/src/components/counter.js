import React, { Component } from "react";

class Counter extends Component {
  // state object includes any data (variables) this component would need when being rendered
  // so when state changes, React "reacts" and rebuilds this component in the physical DOM?
  state = {
    count: 0,
  };

  styles = {
    fontSize: 100,
    fontWeight: "bold",
  };

  render() {
    return (
      <div>
        <span style={this.styles} className="badge badge-primary m-2">
          {this.formatCount()}
        </span>
        <button className="btn btn-secondary btn-sm">Increment</button>
      </div>
    );
  }

  formatCount() {
    const { count } = this.state;
    return count === 0 ? "Zero" : count;
  }
}

export default Counter;
